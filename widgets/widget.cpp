#include "widget.h"
#include <QVBoxLayout>


#include "newview.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_mainWidget = new QStackedWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_mainWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    setLayout(mainLayout);


    m_menuWidget = new MenuWidget();
    m_newView = new NewView();

    m_mainWidget->addWidget(m_menuWidget);
    m_mainWidget->addWidget(m_newView);
    m_mainWidget->setCurrentIndex(1);

    createConnections();
}

Widget::~Widget()
{

}

void Widget::createConnections()
{
    connect(m_newView, &NewView::signalBackToMenu, this, &Widget::slotOpenMenuWidget);

    connect(m_menuWidget, &MenuWidget::signalPlayClicked, this, &Widget::slotOpenPlayWidget);
    connect(m_menuWidget, &MenuWidget::signaleOptionsClicked, this, &Widget::slotOpenMenuWidget);
}

void Widget::slotOpenPlayWidget()
{
    m_mainWidget->setCurrentIndex(1);
}

void Widget::slotOpenMenuWidget()
{
    m_mainWidget->setCurrentIndex(0);
}
