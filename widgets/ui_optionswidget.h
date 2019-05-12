/********************************************************************************
** Form generated from reading UI file 'optionswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSWIDGET_H
#define UI_OPTIONSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *wLabel;
    QLabel *label_8;
    QLabel *moveupLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sLabel;
    QLabel *label_9;
    QLabel *movednLabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *dLabel;
    QLabel *label_10;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *aLabel;
    QLabel *label_11;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_6;
    QLabel *rArrowLabel;
    QLabel *label_12;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lArrowLabel;
    QLabel *label_13;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_8;
    QLabel *spaceLabel;
    QLabel *label_14;
    QLabel *label_21;
    QHBoxLayout *horizontalLayout_10;
    QLabel *backspLabel;
    QLabel *label_23;
    QLabel *label_24;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *backKButton;
    QPushButton *otherButton;
    QWidget *stackedWidgetPage2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_22;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout;
    QSlider *musicSlider;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_13;
    QSlider *soundSlider;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *keyboardButton;
    QPushButton *backKButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        Widget->setAutoFillBackground(true);
        Widget->setStyleSheet(QLatin1String("background-image: url(\"qrc:/sprites/sprites/background_image.png\");\n"
"\n"
"QTabWidget::pane\n"
"{\n"
"    border-top: 2px solid #1B1B1B;\n"
"    background-color: #262626;\n"
"}\n"
"\n"
"QTabWidget::tab-bar\n"
"{\n"
"    left: 5px;\n"
"    alignment: left;\n"
"    background: #3E3E3E;\n"
"}\n"
"\n"
"QTabBar::tab\n"
"{\n"
"    background: transparent;\n"
"    color: #757575;\n"
"    padding: 15px 5px 15px 5px;\n"
"}"));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QLatin1String("QWidget#stackedWidgetPage1\n"
"{\n"
" background-image: url(:/sprites/Background_Image.png)\n"
"}\n"
"\n"
"QWidget#stackedWidgetPage2\n"
"{\n"
" background-image: url(:/sprites/Background_Image.png)\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
" border: 1px solid rgb(120,0,0);\n"
"border-radius: 5px;\n"
"background-color: rgb(110, 0, 0);\n"
"color: white;\n"
"\n"
"}"));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName(QStringLiteral("stackedWidgetPage1"));
        verticalLayout_2 = new QVBoxLayout(stackedWidgetPage1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        wLabel = new QLabel(stackedWidgetPage1);
        wLabel->setObjectName(QStringLiteral("wLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wLabel->sizePolicy().hasHeightForWidth());
        wLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(32);
        wLabel->setFont(font);
        wLabel->setStyleSheet(QStringLiteral("background-image: url(qrc:/sprites/sprites/background_image.png)"));
        wLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(wLabel);

        label_8 = new QLabel(stackedWidgetPage1);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_8);

        moveupLabel = new QLabel(stackedWidgetPage1);
        moveupLabel->setObjectName(QStringLiteral("moveupLabel"));
        sizePolicy.setHeightForWidth(moveupLabel->sizePolicy().hasHeightForWidth());
        moveupLabel->setSizePolicy(sizePolicy);
        moveupLabel->setFont(font);
        moveupLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(moveupLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        sLabel = new QLabel(stackedWidgetPage1);
        sLabel->setObjectName(QStringLiteral("sLabel"));
        sLabel->setFont(font);
        sLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(sLabel);

        label_9 = new QLabel(stackedWidgetPage1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);

        movednLabel = new QLabel(stackedWidgetPage1);
        movednLabel->setObjectName(QStringLiteral("movednLabel"));
        movednLabel->setFont(font);
        movednLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(movednLabel);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        dLabel = new QLabel(stackedWidgetPage1);
        dLabel->setObjectName(QStringLiteral("dLabel"));
        dLabel->setFont(font);
        dLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(dLabel);

        label_10 = new QLabel(stackedWidgetPage1);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_10);

        label_17 = new QLabel(stackedWidgetPage1);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);
        label_17->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_17);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        aLabel = new QLabel(stackedWidgetPage1);
        aLabel->setObjectName(QStringLiteral("aLabel"));
        aLabel->setFont(font);
        aLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(aLabel);

        label_11 = new QLabel(stackedWidgetPage1);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_11);

        label_18 = new QLabel(stackedWidgetPage1);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);
        label_18->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_18);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        rArrowLabel = new QLabel(stackedWidgetPage1);
        rArrowLabel->setObjectName(QStringLiteral("rArrowLabel"));
        rArrowLabel->setFont(font);
        rArrowLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(rArrowLabel);

        label_12 = new QLabel(stackedWidgetPage1);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_12);

        label_19 = new QLabel(stackedWidgetPage1);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_19);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lArrowLabel = new QLabel(stackedWidgetPage1);
        lArrowLabel->setObjectName(QStringLiteral("lArrowLabel"));
        lArrowLabel->setFont(font);
        lArrowLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(lArrowLabel);

        label_13 = new QLabel(stackedWidgetPage1);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_13);

        label_20 = new QLabel(stackedWidgetPage1);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_20);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        spaceLabel = new QLabel(stackedWidgetPage1);
        spaceLabel->setObjectName(QStringLiteral("spaceLabel"));
        spaceLabel->setFont(font);
        spaceLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(spaceLabel);

        label_14 = new QLabel(stackedWidgetPage1);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_14);

        label_21 = new QLabel(stackedWidgetPage1);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_21);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        backspLabel = new QLabel(stackedWidgetPage1);
        backspLabel->setObjectName(QStringLiteral("backspLabel"));
        backspLabel->setFont(font);
        backspLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(backspLabel);

        label_23 = new QLabel(stackedWidgetPage1);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_23);

        label_24 = new QLabel(stackedWidgetPage1);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_24);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        backKButton = new QPushButton(stackedWidgetPage1);
        backKButton->setObjectName(QStringLiteral("backKButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(backKButton->sizePolicy().hasHeightForWidth());
        backKButton->setSizePolicy(sizePolicy1);
        backKButton->setMinimumSize(QSize(220, 40));
        QFont font1;
        font1.setPointSize(30);
        backKButton->setFont(font1);
        backKButton->setStyleSheet(QStringLiteral(""));

        horizontalLayout_11->addWidget(backKButton);

        otherButton = new QPushButton(stackedWidgetPage1);
        otherButton->setObjectName(QStringLiteral("otherButton"));
        sizePolicy1.setHeightForWidth(otherButton->sizePolicy().hasHeightForWidth());
        otherButton->setSizePolicy(sizePolicy1);
        otherButton->setMinimumSize(QSize(220, 50));
        otherButton->setFont(font1);

        horizontalLayout_11->addWidget(otherButton);


        verticalLayout_2->addLayout(horizontalLayout_11);

        stackedWidget->addWidget(stackedWidgetPage1);
        stackedWidgetPage2 = new QWidget();
        stackedWidgetPage2->setObjectName(QStringLiteral("stackedWidgetPage2"));
        verticalLayout_3 = new QVBoxLayout(stackedWidgetPage2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_22 = new QLabel(stackedWidgetPage2);
        label_22->setObjectName(QStringLiteral("label_22"));
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setFont(font);
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_22);

        comboBox = new QComboBox(stackedWidgetPage2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setMinimumSize(QSize(0, 0));
        comboBox->setFont(font1);
        comboBox->setStyleSheet(QLatin1String("QComboBox {\n"
"    border: 1px solid gray;\n"
"    border-radius: 3px;\n"
"	padding: 20 20 20 50;\n"
"	background-color: orange;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"    background: orange;\n"
"	min-width: 25px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 28px;\n"
"}"));
        comboBox->setEditable(false);
        comboBox->setInsertPolicy(QComboBox::InsertAtBottom);
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox->setMinimumContentsLength(0);
        comboBox->setFrame(false);

        horizontalLayout_14->addWidget(comboBox);


        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setSizeConstraint(QLayout::SetMaximumSize);
        label_15 = new QLabel(stackedWidgetPage2);
        label_15->setObjectName(QStringLiteral("label_15"));
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setFont(font);
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_15);


        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 15);
        musicSlider = new QSlider(stackedWidgetPage2);
        musicSlider->setObjectName(QStringLiteral("musicSlider"));
        musicSlider->setMinimumSize(QSize(0, 40));
        musicSlider->setMaximum(100);
        musicSlider->setOrientation(Qt::Horizontal);
        musicSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(musicSlider);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_16 = new QLabel(stackedWidgetPage2);
        label_16->setObjectName(QStringLiteral("label_16"));
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);
        label_16->setFont(font);
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_16);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(-1, -1, -1, 15);
        soundSlider = new QSlider(stackedWidgetPage2);
        soundSlider->setObjectName(QStringLiteral("soundSlider"));
        soundSlider->setMinimumSize(QSize(0, 40));
        soundSlider->setMaximum(100);
        soundSlider->setOrientation(Qt::Horizontal);
        soundSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_13->addWidget(soundSlider);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        keyboardButton = new QPushButton(stackedWidgetPage2);
        keyboardButton->setObjectName(QStringLiteral("keyboardButton"));
        sizePolicy1.setHeightForWidth(keyboardButton->sizePolicy().hasHeightForWidth());
        keyboardButton->setSizePolicy(sizePolicy1);
        keyboardButton->setMinimumSize(QSize(220, 50));
        keyboardButton->setFont(font1);

        horizontalLayout_15->addWidget(keyboardButton);

        backKButton_2 = new QPushButton(stackedWidgetPage2);
        backKButton_2->setObjectName(QStringLiteral("backKButton_2"));
        sizePolicy1.setHeightForWidth(backKButton_2->sizePolicy().hasHeightForWidth());
        backKButton_2->setSizePolicy(sizePolicy1);
        backKButton_2->setMinimumSize(QSize(220, 40));
        backKButton_2->setFont(font1);
        backKButton_2->setStyleSheet(QStringLiteral(""));

        horizontalLayout_15->addWidget(backKButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_15);

        stackedWidget->addWidget(stackedWidgetPage2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        wLabel->setText(QApplication::translate("Widget", "W", nullptr));
        label_8->setText(QApplication::translate("Widget", "-", nullptr));
        moveupLabel->setText(QApplication::translate("Widget", "Move up", nullptr));
        sLabel->setText(QApplication::translate("Widget", "S", nullptr));
        label_9->setText(QApplication::translate("Widget", "-", nullptr));
        movednLabel->setText(QApplication::translate("Widget", "Move down", nullptr));
        dLabel->setText(QApplication::translate("Widget", "D", nullptr));
        label_10->setText(QApplication::translate("Widget", "-", nullptr));
        label_17->setText(QApplication::translate("Widget", "Move right", nullptr));
        aLabel->setText(QApplication::translate("Widget", "A", nullptr));
        label_11->setText(QApplication::translate("Widget", "-", nullptr));
        label_18->setText(QApplication::translate("Widget", "Move left", nullptr));
        rArrowLabel->setText(QApplication::translate("Widget", "->", nullptr));
        label_12->setText(QApplication::translate("Widget", "-", nullptr));
        label_19->setText(QApplication::translate("Widget", "Rotate left", nullptr));
        lArrowLabel->setText(QApplication::translate("Widget", "<-", nullptr));
        label_13->setText(QApplication::translate("Widget", "-", nullptr));
        label_20->setText(QApplication::translate("Widget", "Rotate right", nullptr));
        spaceLabel->setText(QApplication::translate("Widget", "SPACEBAR", nullptr));
        label_14->setText(QApplication::translate("Widget", "-", nullptr));
        label_21->setText(QApplication::translate("Widget", "Shoot", nullptr));
        backspLabel->setText(QApplication::translate("Widget", "BACKSPACE", nullptr));
        label_23->setText(QApplication::translate("Widget", "-", nullptr));
        label_24->setText(QApplication::translate("Widget", "Back", nullptr));
        backKButton->setText(QApplication::translate("Widget", "Back", nullptr));
        otherButton->setText(QApplication::translate("Widget", "Other", nullptr));
        label_22->setText(QApplication::translate("Widget", "Resolution (4:3)", nullptr));
        comboBox->setItemText(0, QApplication::translate("Widget", "800x600", nullptr));
        comboBox->setItemText(1, QApplication::translate("Widget", "1024x768", nullptr));
        comboBox->setItemText(2, QApplication::translate("Widget", "1366x768", nullptr));
        comboBox->setItemText(3, QApplication::translate("Widget", "Full Screen", nullptr));

        label_15->setText(QApplication::translate("Widget", "Background-music", nullptr));
        label_16->setText(QApplication::translate("Widget", "Background-sound", nullptr));
        keyboardButton->setText(QApplication::translate("Widget", "Keyboard", nullptr));
        backKButton_2->setText(QApplication::translate("Widget", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSWIDGET_H
