/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *quitBtn;
    QPushButton *messageBtn;
    QPushButton *infoBtn;
    QLabel *imgLb;
    QLabel *mapImg;
    QPushButton *collectBtn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer;
    QPushButton *west;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *northBtn;
    QPushButton *teleportBtn;
    QPushButton *southBtn;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_3;
    QPushButton *eastBtn;
    QSpacerItem *verticalSpacer_4;
    QListWidget *listWidget;
    QLabel *label;
    QPushButton *bag;
    QLabel *moveLb;
    QLabel *potionLb;
    QPushButton *activation;
    QProgressBar *progressBar;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *element1;
    QLabel *element3;
    QLabel *element5;
    QVBoxLayout *verticalLayout_3;
    QLabel *element2;
    QLabel *element4;
    QLabel *element6;
    QTextEdit *output;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(885, 649);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(890, 650));
        QFont font;
        font.setFamilies({QString::fromUtf8("Century")});
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        quitBtn = new QPushButton(centralwidget);
        quitBtn->setObjectName(QString::fromUtf8("quitBtn"));
        quitBtn->setGeometry(QRect(780, 0, 61, 61));
        QPalette palette;
        QBrush brush(QColor(20, 105, 185, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        QBrush brush2(QColor(208, 208, 208, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush3(QColor(164, 166, 168, 96));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        quitBtn->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century")});
        font1.setPointSize(11);
        quitBtn->setFont(font1);
        quitBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 105, 185);"));
        quitBtn->setAutoDefault(false);
        quitBtn->setFlat(false);
        messageBtn = new QPushButton(centralwidget);
        messageBtn->setObjectName(QString::fromUtf8("messageBtn"));
        messageBtn->setGeometry(QRect(680, 0, 91, 61));
        QPalette palette1;
        QBrush brush4(QColor(217, 144, 108, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        messageBtn->setPalette(palette1);
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Century")});
        font2.setPointSize(9);
        messageBtn->setFont(font2);
        messageBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 144, 108);"));
        infoBtn = new QPushButton(centralwidget);
        infoBtn->setObjectName(QString::fromUtf8("infoBtn"));
        infoBtn->setGeometry(QRect(580, 0, 91, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        infoBtn->setPalette(palette2);
        infoBtn->setFont(font1);
        infoBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 144, 108);"));
        imgLb = new QLabel(centralwidget);
        imgLb->setObjectName(QString::fromUtf8("imgLb"));
        imgLb->setGeometry(QRect(10, 20, 431, 271));
        imgLb->setFrameShape(QFrame::Box);
        imgLb->setFrameShadow(QFrame::Plain);
        imgLb->setScaledContents(true);
        mapImg = new QLabel(centralwidget);
        mapImg->setObjectName(QString::fromUtf8("mapImg"));
        mapImg->setGeometry(QRect(440, 360, 411, 221));
        mapImg->setFrameShape(QFrame::StyledPanel);
        mapImg->setFrameShadow(QFrame::Raised);
        mapImg->setTextFormat(Qt::AutoText);
        mapImg->setScaledContents(true);
        collectBtn = new QPushButton(centralwidget);
        collectBtn->setObjectName(QString::fromUtf8("collectBtn"));
        collectBtn->setGeometry(QRect(120, 310, 281, 29));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush);
        collectBtn->setPalette(palette3);
        collectBtn->setFont(font2);
        collectBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 105, 185);"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 390, 421, 191));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        west = new QPushButton(horizontalLayoutWidget);
        west->setObjectName(QString::fromUtf8("west"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(west->sizePolicy().hasHeightForWidth());
        west->setSizePolicy(sizePolicy1);
        QPalette palette4;
        QBrush brush5(QColor(195, 130, 97, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        west->setPalette(palette4);
        west->setFont(font);
        west->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 130, 97);"));

        verticalLayout_6->addWidget(west);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        northBtn = new QPushButton(horizontalLayoutWidget);
        northBtn->setObjectName(QString::fromUtf8("northBtn"));
        sizePolicy1.setHeightForWidth(northBtn->sizePolicy().hasHeightForWidth());
        northBtn->setSizePolicy(sizePolicy1);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        northBtn->setPalette(palette5);
        northBtn->setFont(font);
        northBtn->setFocusPolicy(Qt::NoFocus);
        northBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 130, 97);"));
        northBtn->setAutoDefault(false);

        verticalLayout->addWidget(northBtn);

        teleportBtn = new QPushButton(horizontalLayoutWidget);
        teleportBtn->setObjectName(QString::fromUtf8("teleportBtn"));
        sizePolicy1.setHeightForWidth(teleportBtn->sizePolicy().hasHeightForWidth());
        teleportBtn->setSizePolicy(sizePolicy1);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        teleportBtn->setPalette(palette6);
        teleportBtn->setFont(font);
        teleportBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 105, 185);"));
        teleportBtn->setInputMethodHints(Qt::ImhNone);
        teleportBtn->setFlat(false);

        verticalLayout->addWidget(teleportBtn);

        southBtn = new QPushButton(horizontalLayoutWidget);
        southBtn->setObjectName(QString::fromUtf8("southBtn"));
        sizePolicy1.setHeightForWidth(southBtn->sizePolicy().hasHeightForWidth());
        southBtn->setSizePolicy(sizePolicy1);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        southBtn->setPalette(palette7);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Century")});
        font3.setPointSize(10);
        font3.setItalic(false);
        southBtn->setFont(font3);
        southBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 130, 97);"));

        verticalLayout->addWidget(southBtn);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        eastBtn = new QPushButton(horizontalLayoutWidget);
        eastBtn->setObjectName(QString::fromUtf8("eastBtn"));
        sizePolicy1.setHeightForWidth(eastBtn->sizePolicy().hasHeightForWidth());
        eastBtn->setSizePolicy(sizePolicy1);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        eastBtn->setPalette(palette8);
        eastBtn->setFont(font);
        eastBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(195, 130, 97);"));
        eastBtn->setIconSize(QSize(30, 30));
        eastBtn->setAutoDefault(false);

        verticalLayout_7->addWidget(eastBtn);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_7);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(470, 270, 371, 71));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 203, 203);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 320, 61, 20));
        bag = new QPushButton(centralwidget);
        bag->setObjectName(QString::fromUtf8("bag"));
        bag->setGeometry(QRect(470, 0, 101, 61));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        bag->setPalette(palette9);
        bag->setFont(font1);
        bag->setStyleSheet(QString::fromUtf8("background-color: rgb(217, 144, 108);"));
        moveLb = new QLabel(centralwidget);
        moveLb->setObjectName(QString::fromUtf8("moveLb"));
        moveLb->setGeometry(QRect(10, 320, 101, 20));
        moveLb->setFont(font2);
        moveLb->setFrameShape(QFrame::NoFrame);
        potionLb = new QLabel(centralwidget);
        potionLb->setObjectName(QString::fromUtf8("potionLb"));
        potionLb->setGeometry(QRect(10, 350, 111, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Century")});
        font4.setPointSize(8);
        potionLb->setFont(font4);
        potionLb->setFrameShape(QFrame::NoFrame);
        potionLb->setFrameShadow(QFrame::Plain);
        activation = new QPushButton(centralwidget);
        activation->setObjectName(QString::fromUtf8("activation"));
        activation->setGeometry(QRect(290, 350, 111, 31));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush);
        activation->setPalette(palette10);
        activation->setFont(font2);
        activation->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 105, 185);"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(120, 350, 171, 31));
        progressBar->setStyleSheet(QString::fromUtf8(""));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Horizontal);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(710, 70, 131, 191));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        element1 = new QLabel(groupBox);
        element1->setObjectName(QString::fromUtf8("element1"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(element1->sizePolicy().hasHeightForWidth());
        element1->setSizePolicy(sizePolicy2);
        element1->setMaximumSize(QSize(45, 45));
        element1->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        element1->setFrameShape(QFrame::WinPanel);
        element1->setFrameShadow(QFrame::Sunken);
        element1->setScaledContents(true);

        verticalLayout_2->addWidget(element1);

        element3 = new QLabel(groupBox);
        element3->setObjectName(QString::fromUtf8("element3"));
        sizePolicy2.setHeightForWidth(element3->sizePolicy().hasHeightForWidth());
        element3->setSizePolicy(sizePolicy2);
        element3->setMaximumSize(QSize(45, 45));
        element3->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        element3->setFrameShape(QFrame::WinPanel);
        element3->setFrameShadow(QFrame::Sunken);
        element3->setScaledContents(true);

        verticalLayout_2->addWidget(element3);

        element5 = new QLabel(groupBox);
        element5->setObjectName(QString::fromUtf8("element5"));
        sizePolicy2.setHeightForWidth(element5->sizePolicy().hasHeightForWidth());
        element5->setSizePolicy(sizePolicy2);
        element5->setMaximumSize(QSize(45, 45));
        element5->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        element5->setFrameShape(QFrame::WinPanel);
        element5->setFrameShadow(QFrame::Sunken);
        element5->setScaledContents(true);

        verticalLayout_2->addWidget(element5);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        element2 = new QLabel(groupBox);
        element2->setObjectName(QString::fromUtf8("element2"));
        sizePolicy2.setHeightForWidth(element2->sizePolicy().hasHeightForWidth());
        element2->setSizePolicy(sizePolicy2);
        element2->setMaximumSize(QSize(45, 45));
        element2->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        element2->setFrameShape(QFrame::WinPanel);
        element2->setFrameShadow(QFrame::Sunken);
        element2->setScaledContents(true);

        verticalLayout_3->addWidget(element2);

        element4 = new QLabel(groupBox);
        element4->setObjectName(QString::fromUtf8("element4"));
        sizePolicy2.setHeightForWidth(element4->sizePolicy().hasHeightForWidth());
        element4->setSizePolicy(sizePolicy2);
        element4->setMaximumSize(QSize(45, 45));
        element4->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        element4->setFrameShape(QFrame::WinPanel);
        element4->setFrameShadow(QFrame::Sunken);
        element4->setScaledContents(true);

        verticalLayout_3->addWidget(element4);

        element6 = new QLabel(groupBox);
        element6->setObjectName(QString::fromUtf8("element6"));
        sizePolicy2.setHeightForWidth(element6->sizePolicy().hasHeightForWidth());
        element6->setSizePolicy(sizePolicy2);
        element6->setMaximumSize(QSize(45, 45));
        element6->setStyleSheet(QString::fromUtf8("background-color: rgb(121, 121, 121);"));
        element6->setFrameShape(QFrame::WinPanel);
        element6->setFrameShadow(QFrame::Sunken);
        element6->setScaledContents(true);

        verticalLayout_3->addWidget(element6);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        output = new QTextEdit(centralwidget);
        output->setObjectName(QString::fromUtf8("output"));
        output->setGeometry(QRect(470, 70, 231, 192));
        output->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 203, 203);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 885, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(collectBtn, &QPushButton::clicked, progressBar, qOverload<>(&QProgressBar::reset));

        quitBtn->setDefault(false);
        northBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "The Land Of Loswilire", nullptr));
        quitBtn->setText(QCoreApplication::translate("MainWindow", "QUIT", nullptr));
        messageBtn->setText(QCoreApplication::translate("MainWindow", "MESSAGE!!", nullptr));
        infoBtn->setText(QCoreApplication::translate("MainWindow", "HELP", nullptr));
        imgLb->setText(QString());
        mapImg->setText(QString());
        collectBtn->setText(QCoreApplication::translate("MainWindow", " COLLECT A ITEM", nullptr));
        west->setText(QCoreApplication::translate("MainWindow", "WEST", nullptr));
        northBtn->setText(QCoreApplication::translate("MainWindow", "NORTH", nullptr));
        teleportBtn->setText(QCoreApplication::translate("MainWindow", "TELEPORT", nullptr));
        southBtn->setText(QCoreApplication::translate("MainWindow", "SOUTH", nullptr));
        eastBtn->setText(QCoreApplication::translate("MainWindow", "EAST", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "==>>>>", nullptr));
        bag->setText(QCoreApplication::translate("MainWindow", "BAG", nullptr));
        moveLb->setText(QCoreApplication::translate("MainWindow", "MOVE", nullptr));
        potionLb->setText(QCoreApplication::translate("MainWindow", "MAGIC POTION", nullptr));
        activation->setText(QCoreApplication::translate("MainWindow", "ACTIVATION", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "ELements:", nullptr));
        element1->setText(QString());
        element3->setText(QString());
        element5->setText(QString());
        element2->setText(QString());
        element4->setText(QString());
        element6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
