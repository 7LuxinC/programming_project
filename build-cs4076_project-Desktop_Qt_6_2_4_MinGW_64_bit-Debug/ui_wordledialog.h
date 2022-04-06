/********************************************************************************
** Form generated from reading UI file 'wordledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDLEDIALOG_H
#define UI_WORDLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WordleDialog
{
public:
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *opText;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *typedWords;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *WordleDialog)
    {
        if (WordleDialog->objectName().isEmpty())
            WordleDialog->setObjectName(QString::fromUtf8("WordleDialog"));
        WordleDialog->resize(681, 587);
        WordleDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 159, 255);"));
        verticalLayout_6 = new QVBoxLayout(WordleDialog);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        pushButton = new QPushButton(WordleDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QPalette palette;
        QBrush brush(QColor(8, 107, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(208, 203, 208, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush2(QColor(64, 65, 66, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        QBrush brush3(QColor(208, 208, 208, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush3);
        QBrush brush4(QColor(46, 47, 48, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush5(QColor(164, 166, 168, 96));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton->setPalette(palette);
        QFont font;
        font.setFamilies({QString::fromUtf8("Century")});
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(8, 107, 255);"));
        pushButton->setAutoDefault(false);

        verticalLayout_5->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(WordleDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Century")});
        font1.setPointSize(14);
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 159, 255);"));

        verticalLayout->addWidget(label_3);

        opText = new QTextEdit(WordleDialog);
        opText->setObjectName(QString::fromUtf8("opText"));
        QFont font2;
        font2.setPointSize(12);
        opText->setFont(font2);
        opText->setStyleSheet(QString::fromUtf8("background-color: rgb(98, 111, 127);"));

        verticalLayout->addWidget(opText);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(WordleDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        typedWords = new QTextEdit(WordleDialog);
        typedWords->setObjectName(QString::fromUtf8("typedWords"));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Century")});
        font3.setPointSize(28);
        typedWords->setFont(font3);
        typedWords->setStyleSheet(QString::fromUtf8("background-color: rgb(98, 111, 127);"));

        verticalLayout_2->addWidget(typedWords);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label_2 = new QLabel(WordleDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        lineEdit = new QLineEdit(WordleDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 200, 200);"));

        verticalLayout_3->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(WordleDialog);

        QMetaObject::connectSlotsByName(WordleDialog);
    } // setupUi

    void retranslateUi(QDialog *WordleDialog)
    {
        WordleDialog->setWindowTitle(QCoreApplication::translate("WordleDialog", "WORDLE WORLD", nullptr));
        pushButton->setText(QCoreApplication::translate("WordleDialog", "Rule of Wordle game", nullptr));
        label_3->setText(QCoreApplication::translate("WordleDialog", "Output:", nullptr));
        label->setText(QCoreApplication::translate("WordleDialog", "Words :", nullptr));
        label_2->setText(QCoreApplication::translate("WordleDialog", "Guess a word:", nullptr));
        lineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WordleDialog: public Ui_WordleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDLEDIALOG_H
