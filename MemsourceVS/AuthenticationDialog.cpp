#include "AuthenticationDialog.h"
#include <QAbstractButton>

#include "ProjectListWindow.h"

AuthenticationDialog::AuthenticationDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.loginBtn, &QAbstractButton::clicked, this, &QDialog::accept);
}

AuthenticationDialog::~AuthenticationDialog()
{
}

QString AuthenticationDialog::getLogin()
{
	return QString(ui.loginIn->text());
}

QString AuthenticationDialog::getPasswd()
{
	return QString(ui.passwordIn->text());
}
