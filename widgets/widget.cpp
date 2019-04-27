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
