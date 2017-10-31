#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjectListWindow.h"

class ProjectListWindow : public QMainWindow
{
	Q_OBJECT

public:
	ProjectListWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::ProjectListWindowClass ui;
};
