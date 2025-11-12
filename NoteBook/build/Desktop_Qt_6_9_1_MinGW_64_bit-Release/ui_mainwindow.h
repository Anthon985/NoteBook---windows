/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *hLayoutBtn;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;
    QLabel *lblFileName;
    QTextEdit *textEdit;
    QWidget *widget_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblCursorPos;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(738, 621);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/biji.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(0, 38));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 244, 244);"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        hLayoutBtn = new QHBoxLayout();
        hLayoutBtn->setObjectName("hLayoutBtn");
        hLayoutBtn->setContentsMargins(0, -1, -1, -1);
        btnOpen = new QPushButton(widget);
        btnOpen->setObjectName("btnOpen");
        btnOpen->setMinimumSize(QSize(25, 25));
        btnOpen->setMaximumSize(QSize(25, 25));
        btnOpen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-image: url(:/icon/open.png) stretch; /* \350\203\214\346\231\257\345\233\276\357\274\210\346\233\277\344\273\243 border-image\357\274\214\346\233\264\351\200\202\345\220\210\350\203\214\346\231\257\345\234\272\346\231\257\357\274\211*/\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(233, 233, 233);\n"
"}"));

        hLayoutBtn->addWidget(btnOpen);

        btnSave = new QPushButton(widget);
        btnSave->setObjectName("btnSave");
        btnSave->setMinimumSize(QSize(25, 23));
        btnSave->setMaximumSize(QSize(25, 23));
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/icon/save.png);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(233, 233, 233);\n"
"}\n"
""));

        hLayoutBtn->addWidget(btnSave);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(23, 25));
        btnClose->setMaximumSize(QSize(23, 25));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/icon/close.png);\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: rgb(233, 233, 233);\n"
"}"));

        hLayoutBtn->addWidget(btnClose);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutBtn->addItem(horizontalSpacer);


        horizontalLayout->addLayout(hLayoutBtn);


        verticalLayout->addWidget(widget);

        lblFileName = new QLabel(centralwidget);
        lblFileName->setObjectName("lblFileName");
        lblFileName->setMaximumSize(QSize(100, 50));
        lblFileName->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 244, 244);"));

        verticalLayout->addWidget(lblFileName);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(textEdit);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setMinimumSize(QSize(0, 38));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 244, 244);"));
        layoutWidget = new QWidget(widget_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 10, 711, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblCursorPos = new QLabel(layoutWidget);
        lblCursorPos->setObjectName("lblCursorPos");
        lblCursorPos->setMinimumSize(QSize(85, 0));
        lblCursorPos->setMaximumSize(QSize(85, 16777215));

        horizontalLayout_2->addWidget(lblCursorPos);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NoteBook", nullptr));
        btnOpen->setText(QString());
        btnSave->setText(QString());
        btnClose->setText(QString());
        lblFileName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblCursorPos->setText(QCoreApplication::translate("MainWindow", "\350\241\214 1\357\274\214\345\210\227 1", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "UTF-8", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "UTF-16", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "ANSI", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "GBK", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
