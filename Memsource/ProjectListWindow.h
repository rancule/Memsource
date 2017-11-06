#pragma once

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include "ui_ProjectListWindow.h"
#include "AuthenticationDialog.h"

class ProjectListWindow : public QMainWindow
{
	Q_OBJECT

public:
	ProjectListWindow(QWidget *parent = Q_NULLPTR);
	~ProjectListWindow();

private:
	Ui::ProjectListWindowClass ui;
	QNetworkAccessManager accessManager;
	QNetworkReply* reply;
	AuthenticationDialog authenticationDlg;
	QStandardItemModel* model;

	QString getToken(QByteArray replyData);
	void fillProjectsData(const QJsonArray& projectsList);
	QString getTargetLangsList(const QJsonArray& targetLangs);

	private slots:
	void networkFailed(QNetworkReply::NetworkError);
	void authenticate();
	void getProjects(QString token);
	void getProjectsFinished();
	void authenticationFinished();

	signals:
	void authenticated(QString token);
};
