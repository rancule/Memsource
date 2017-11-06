/********************************************************************************
** Form generated from reading UI file 'AuthenticationDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATIONDIALOG_H
#define UI_AUTHENTICATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AuthenticationDialog
{
public:
    QLineEdit *loginIn;
    QLineEdit *passwordIn;
    QPushButton *loginBtn;
    QLabel *usernameLbl;
    QLabel *passwordLbl;

    void setupUi(QDialog *AuthenticationDialog)
    {
        if (AuthenticationDialog->objectName().isEmpty())
            AuthenticationDialog->setObjectName(QStringLiteral("AuthenticationDialog"));
        AuthenticationDialog->resize(231, 102);
        loginIn = new QLineEdit(AuthenticationDialog);
        loginIn->setObjectName(QStringLiteral("loginIn"));
        loginIn->setGeometry(QRect(70, 10, 151, 20));
        passwordIn = new QLineEdit(AuthenticationDialog);
        passwordIn->setObjectName(QStringLiteral("passwordIn"));
        passwordIn->setGeometry(QRect(70, 40, 151, 20));
        passwordIn->setEchoMode(QLineEdit::Password);
        loginBtn = new QPushButton(AuthenticationDialog);
        loginBtn->setObjectName(QStringLiteral("loginBtn"));
        loginBtn->setGeometry(QRect(150, 70, 71, 23));
        usernameLbl = new QLabel(AuthenticationDialog);
        usernameLbl->setObjectName(QStringLiteral("usernameLbl"));
        usernameLbl->setGeometry(QRect(10, 10, 47, 13));
        usernameLbl->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        passwordLbl = new QLabel(AuthenticationDialog);
        passwordLbl->setObjectName(QStringLiteral("passwordLbl"));
        passwordLbl->setGeometry(QRect(10, 40, 47, 13));
        passwordLbl->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        retranslateUi(AuthenticationDialog);

        QMetaObject::connectSlotsByName(AuthenticationDialog);
    } // setupUi

    void retranslateUi(QDialog *AuthenticationDialog)
    {
        AuthenticationDialog->setWindowTitle(QApplication::translate("AuthenticationDialog", "Login", Q_NULLPTR));
        loginBtn->setText(QApplication::translate("AuthenticationDialog", "Login", Q_NULLPTR));
        usernameLbl->setText(QApplication::translate("AuthenticationDialog", "Username", Q_NULLPTR));
        passwordLbl->setText(QApplication::translate("AuthenticationDialog", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthenticationDialog: public Ui_AuthenticationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATIONDIALOG_H
