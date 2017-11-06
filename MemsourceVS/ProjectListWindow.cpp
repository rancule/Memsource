#include "ProjectListWindow.h"
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

ProjectListWindow::ProjectListWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.getProjectsBtn, &QAbstractButton::clicked, this, &ProjectListWindow::authenticate);
	connect(this, SIGNAL(authenticated(QString)), this, SLOT(getProjects(QString)));

	model = new QStandardItemModel(0, 4, this); //0 Rows and 4 Columns
	model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
	model->setHorizontalHeaderItem(1, new QStandardItem(QString("Source language")));
	model->setHorizontalHeaderItem(2, new QStandardItem(QString("Target languages")));
	model->setHorizontalHeaderItem(3, new QStandardItem(QString("Date of creation")));
	ui.projectsData->setModel(model);
}

ProjectListWindow::~ProjectListWindow()
{
	delete model;
}

void ProjectListWindow::networkFailed(QNetworkReply::NetworkError)
{
	QMessageBox::critical(this, "Error", reply->errorString());
}

void ProjectListWindow::authenticate()
{
	if (authenticationDlg.exec() != QDialog::Accepted) return;
	QUrl url("https://cloud.memsource.com/web/api/v3/auth/login"
		"?userName=" + authenticationDlg.getLogin() +
		"&password=" + authenticationDlg.getPasswd());
	reply = accessManager.get(QNetworkRequest(url));
	connect(reply, &QNetworkReply::finished, this, &ProjectListWindow::authenticationFinished);
	connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkFailed(QNetworkReply::NetworkError)));
}

void ProjectListWindow::authenticationFinished()
{
	if (reply->error() != QNetworkReply::NoError) {
		return;
	}

	QString token = getToken(reply->readAll());
	if (!token.isEmpty()) {
		emit authenticated(token);
	}
}

QString ProjectListWindow::getToken(QByteArray replyData)
{
	QJsonDocument jsonResponse = QJsonDocument::fromJson(replyData);
	QJsonObject jsonObject = jsonResponse.object();
	return jsonObject["token"].toString();
}

void ProjectListWindow::getProjects(QString token)
{
	QUrl url("https://cloud.memsource.com/web/api/v3/project/list?token=" + token);
	reply = accessManager.get(QNetworkRequest(url));
	connect(reply, &QNetworkReply::finished, this, &ProjectListWindow::getProjectsFinished);
	connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkFailed(QNetworkReply::NetworkError)));
}

void ProjectListWindow::getProjectsFinished()
{
	if (reply->error() != QNetworkReply::NoError) {
		return;
	}

	QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
	fillProjectsData(jsonResponse.array());
}

void ProjectListWindow::fillProjectsData(const QJsonArray& projectsList)
{
	for (const QJsonValue& projectValue : projectsList) {
		QJsonObject project = projectValue.toObject();
		QList<QStandardItem *> row;
		row.append(new QStandardItem(project["name"].toString()));
		row.append(new QStandardItem(project["sourceLang"].toString()));		
		row.append(new QStandardItem(getTargetLangsList(project["targetLangs"].toArray())));
		QDateTime dateCreated = QDateTime::fromString(project["dateCreated"].toString(), Qt::ISODate);
		row.append(new QStandardItem(dateCreated.toString()));
		model->appendRow(row);
	}
}

QString ProjectListWindow::getTargetLangsList(const QJsonArray& targetLangs)
{
	QString targetLangsList;
	for (int i = 0; i < targetLangs.count(); ++i) {
		targetLangsList += ((i) ? ", " : "") + targetLangs[i].toString();
	}
	return targetLangsList;
}
