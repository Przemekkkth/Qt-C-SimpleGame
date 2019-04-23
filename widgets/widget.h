#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "ui_menuwidget.h"
#include "menuwidget.h"

class NewView;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QStackedWidget *m_mainWidget;
    MenuWidget* m_menuWidget;
    NewView *m_newView;

    void createConnections();

private slots:
    void slotOpenPlayWidget();
    void slotOpenMenuWidget();
};

#endif // WIDGET_H
