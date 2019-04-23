#include "optionswidget.h"
#include "ui_optionswidget.h"

#include <QPainter>
#include <QLabel>
#include <QFontDatabase>
#include <QTableWidget>
#include <QLineEdit>
#include <QDebug>

OptionsWidget::OptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //ui->label->setAttribute(Qt::WA_TranslucentBackground);
    QList<QLabel*> list = ui->stackedWidgetPage1->findChildren<QLabel*>();

    int id = QFontDatabase::addApplicationFont(":/fonts/assets/fonts/adrip1.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);



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
