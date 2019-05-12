#include "widget.h"
#include "newview.h"
#include "optionswidget.h"
#include "ui_optionswidget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,600);
    m_mainWidget = new QStackedWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_mainWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);


    m_menuWidget = new MenuWidget();
    m_newView = new NewView();
    m_optionsWidget = new OptionsWidget();

    m_mainWidget->addWidget(m_menuWidget);
    m_mainWidget->addWidget(m_newView);
    m_mainWidget->addWidget(m_optionsWidget);
    m_mainWidget->setCurrentIndex(0);

    createConnections();
}

Widget::~Widget()
{

}

void Widget::createConnections()
{
    connect(m_newView, &NewView::signalBackToMenu, this, &Widget::slotOpenMenuWidget);

    connect(m_menuWidget, &MenuWidget::signalPlayClicked, this, &Widget::slotOpenPlayWidget);
    connect(m_menuWidget, &MenuWidget::signaleOptionsClicked, this, &Widget::slotOpenOptionsWidget);

    connect(m_optionsWidget, &OptionsWidget::signalBackClicked, this, &Widget::slotOpenMenuWidget);
    connect(m_optionsWidget, &OptionsWidget::signalResolutionChanged, this, &Widget::slotSetResolution);
    connect(m_optionsWidget, &OptionsWidget::signalSetFullScreen, this, &Widget::slotSetFullScreen);
}

void Widget::slotOpenPlayWidget()
{
    m_mainWidget->setCurrentIndex(1);
}

void Widget::slotOpenMenuWidget()
{
    m_mainWidget->setCurrentIndex(0);
}

void Widget::slotOpenOptionsWidget()
{
    m_mainWidget->setCurrentIndex(2);
}

void Widget::slotSetResolution(QString testResolution)
{
    //format Resolution: "(width)x(height)"
    QStringList dataList = testResolution.split("x");
    if(dataList.size() != 2)
    {
        return;
    }
    int width = dataList.at(0).toInt();
    int height = dataList.at(1).toInt();

    resize(width, height);
}

void Widget::slotSetFullScreen()
{
    showFullScreen();
}
