#pragma once

#include <QDialog>
#include "ui_AuthenticationDialog.h"

class AuthenticationDialog : public QDialog
{
	Q_OBJECT

public:
	AuthenticationDialog(QWidget *parent = Q_NULLPTR);
	~AuthenticationDialog();

	QString getLogin();
	QString getPasswd();

private:
	Ui::AuthenticationDialog ui;
};
