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
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *action_6;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *action_9;
    QAction *action;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *action_18;
    QAction *action_19;
    QAction *actionAll;
    QAction *actionTime;
    QAction *actionFont;
    QAction *action_3;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *lblFileName;
    QTextEdit *textEdit;
    QWidget *widget_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblCursorPos;
    QSpacerItem *horizontalSpacer_2;
    QLabel *zoomSize;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu;
    QMenu *menu_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(738, 621);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/biji.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName("actionnew");
        action_6 = new QAction(MainWindow);
        action_6->setObjectName("action_6");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        action_9 = new QAction(MainWindow);
        action_9->setObjectName("action_9");
        action = new QAction(MainWindow);
        action->setObjectName("action");
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName("actionCut");
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        action_18 = new QAction(MainWindow);
        action_18->setObjectName("action_18");
        action_19 = new QAction(MainWindow);
        action_19->setObjectName("action_19");
        actionAll = new QAction(MainWindow);
        actionAll->setObjectName("actionAll");
        actionTime = new QAction(MainWindow);
        actionTime->setObjectName("actionTime");
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName("actionFont");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
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
        layoutWidget->setGeometry(QRect(0, 10, 711, 27));
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

        zoomSize = new QLabel(layoutWidget);
        zoomSize->setObjectName("zoomSize");

        horizontalLayout_2->addWidget(zoomSize);

        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

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
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 738, 25));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menu_3);
        menu_4->setObjectName("menu_4");
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName("menu_5");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu_2->addAction(actionUndo);
        menu_2->addAction(actionCut);
        menu_2->addAction(actionCopy);
        menu_2->addAction(actionPaste);
        menu_2->addSeparator();
        menu_2->addAction(actionAll);
        menu_2->addAction(actionTime);
        menu_3->addAction(menu_4->menuAction());
        menu_4->addAction(action_18);
        menu_4->addAction(action_19);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(action_9);
        menu->addSeparator();
        menu->addAction(actionClose);
        menu_5->addAction(actionFont);
        menu_5->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "NoteBook", nullptr));
        actionnew->setText(QCoreApplication::translate("MainWindow", "new", nullptr));
        action_6->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\347\252\227\345\217\243(N)", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_9->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\347\252\227\345\217\243", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272(D)", nullptr));
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_18->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247(+)", nullptr));
        action_19->setText(QCoreApplication::translate("MainWindow", "\347\274\251\345\260\217(-)", nullptr));
        actionAll->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
#if QT_CONFIG(shortcut)
        actionAll->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTime->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264/\346\227\245\346\234\237", nullptr));
#if QT_CONFIG(shortcut)
        actionTime->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFont->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\350\203\214\346\231\257", nullptr));
        lblFileName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lblCursorPos->setText(QCoreApplication::translate("MainWindow", "\350\241\214 1\357\274\214\345\210\227 1", nullptr));
        zoomSize->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "UTF-8", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "UTF-16", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "ANSI", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "GBK", nullptr));

        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\347\274\251\346\224\276", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
