/********************************************************************************
** Form generated from reading UI file 'ProjectListWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTLISTWINDOW_H
#define UI_PROJECTLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectListWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *getProjectsBtn;
    QTableView *projectsData;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProjectListWindowClass)
    {
        if (ProjectListWindowClass->objectName().isEmpty())
            ProjectListWindowClass->setObjectName(QStringLiteral("ProjectListWindowClass"));
        ProjectListWindowClass->resize(600, 400);
        centralWidget = new QWidget(ProjectListWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        getProjectsBtn = new QPushButton(centralWidget);
        getProjectsBtn->setObjectName(QStringLiteral("getProjectsBtn"));
        getProjectsBtn->setGeometry(QRect(10, 10, 75, 23));
        projectsData = new QTableView(centralWidget);
        projectsData->setObjectName(QStringLiteral("projectsData"));
        projectsData->setGeometry(QRect(10, 40, 581, 301));
        ProjectListWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ProjectListWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        ProjectListWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProjectListWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ProjectListWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ProjectListWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ProjectListWindowClass->setStatusBar(statusBar);

        retranslateUi(ProjectListWindowClass);

        QMetaObject::connectSlotsByName(ProjectListWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectListWindowClass)
    {
        ProjectListWindowClass->setWindowTitle(QApplication::translate("ProjectListWindowClass", "ProjectListWindow", Q_NULLPTR));
        getProjectsBtn->setText(QApplication::translate("ProjectListWindowClass", "Get projects!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProjectListWindowClass: public Ui_ProjectListWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTLISTWINDOW_H
