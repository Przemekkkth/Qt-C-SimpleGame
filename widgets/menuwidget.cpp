#include "menuwidget.h"
#include "ui_menuwidget.h"
#include <QFontDatabase>
#include <QDebug>
#include <QFont>
#include <QLabel>
#include <QFontMetrics>
#include <QDebug>
#include <QPainter>
#include <QResizeEvent>

MenuWidget::MenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuWidget)
{
    ui->setupUi(this);
    int id = QFontDatabase::addApplicationFont(":/fonts/adrip1.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    ui->label->setFont(family);
    ui->label->setStyleSheet("color: red;");
    QFont myFont = ui->label->font();
    myFont.setPixelSize(80);
    myFont.setBold(true);
    myFont.setItalic(true);
    ui->label->setFont(myFont);
    ui->label->setText("Shape\nShooter");

    ui->label->setAttribute(Qt::WA_TranslucentBackground);

    ui->playButton->setFont(QFont(family));
    ui->optionsButton->setFont(QFont(family));
    ui->quitButton->setFont(QFont(family));


    resize(800, 600);

    createStylesheets();
}

MenuWidget::~MenuWidget()
{
    delete ui;
}

void MenuWidget::createStylesheets()
{
    ui->playButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->optionsButton->setCursor(QCursor(Qt::PointingHandCursor));
    ui->quitButton->setCursor(QCursor(Qt::PointingHandCursor));
}

void MenuWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(":/Images/background_image.png"));
}

void MenuWidget::resizeEvent(QResizeEvent* event)
{
    QFont myFont = ui->label->font();
    myFont.setPixelSize(event->size().height()/6);

    QFont buttonsFont = ui->playButton->font();
    buttonsFont.setPixelSize(event->size().height()/22);
    ui->playButton->setFont(buttonsFont);
    ui->optionsButton->setFont(buttonsFont);
    ui->quitButton->setFont(buttonsFont);

}


void MenuWidget::on_optionsButton_clicked()
{
    emit signaleOptionsClicked();
}

void MenuWidget::on_playButton_clicked()
{
    emit signalPlayClicked();
}

void MenuWidget::on_quitButton_clicked()
{
    qApp->quit();
}
