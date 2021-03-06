#include "optionswidget.h"
#include "ui_optionswidget.h"

#include <QPainter>
#include <QLabel>
#include <QFontDatabase>
#include <QTableWidget>
#include <QLineEdit>
#include <QDebug>

#include "../tools/soundmanager.h"

OptionsWidget::OptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->label->setAttribute(Qt::WA_TranslucentBackground);
    QList<QLabel*> list = ui->stackedWidgetPage1->findChildren<QLabel*>();

    int id = QFontDatabase::addApplicationFont(":/fonts/adrip1.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    ui->stackedWidgetPage1->setStyleSheet("QWidget#stackedWidgetPage1{ background-image: url(:/sprites/Background_Image.png)}");
    ui->stackedWidgetPage2->setStyleSheet("QWidget#stackedWidgetPage2{ background-image: url(:/sprites/Background_Image.png)}");


    for(int i = 0; i < list.count(); ++i)
    {
        list.at(i)->setAttribute(Qt::WA_TranslucentBackground);
        list.at(i)->setFont(QFont(family, 32));
    }

    list = ui->stackedWidgetPage2->findChildren<QLabel*>();

    for(int i = 0; i < list.count(); ++i)
    {
        list.at(i)->setAttribute(Qt::WA_TranslucentBackground);
        list.at(i)->setFont(QFont(family, 32));
    }

    ui->backKButton->setFont(QFont(family, 32));
    ui->backKButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->otherButton->setFont(QFont(family, 32));
    ui->otherButton->setCursor(QCursor(Qt::PointingHandCursor));

    ui->backKButton_2->setFont(QFont(family, 32));
    ui->backKButton_2->setCursor(QCursor(Qt::PointingHandCursor));
    ui->keyboardButton->setFont(QFont(family, 32));
    ui->keyboardButton->setCursor(QCursor(Qt::PointingHandCursor));

    ui->comboBox->setFont(QFont(family, 30));
    ui->comboBox->setCursor(QCursor(Qt::PointingHandCursor));

    ui->soundSlider->setCursor(QCursor(Qt::PointingHandCursor));
    ui->musicSlider->setCursor(QCursor(Qt::PointingHandCursor));



    resize(800, 600);
}

OptionsWidget::~OptionsWidget()
{
    delete ui;
}

void OptionsWidget::on_otherButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void OptionsWidget::on_keyboardButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void OptionsWidget::on_backKButton_2_clicked()
{
    emit signalBackClicked();
}

void OptionsWidget::on_backKButton_clicked()
{
    emit signalBackClicked();
}

void OptionsWidget::on_comboBox_currentIndexChanged(const QString &resolutionText)
{
    if(ui->comboBox->currentIndex() == (ui->comboBox->count()-1))
    {
        emit signalSetFullScreen();
    }
    else
    {
        emit signalResolutionChanged(resolutionText);
    }

}

void OptionsWidget::on_musicSlider_valueChanged(int value)
{
    SoundManager::instance()->setBGVolume(value);
}

void OptionsWidget::on_soundSlider_valueChanged(int value)
{
    SoundManager::instance()->setSDVolume(value);
}
