#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include "ui_menuwidget.h"
#include "menuwidget.h"

#include "optionswidget.h"

class NewView;
//class OptionsWidget;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QStackedWidget *m_mainWidget;
    MenuWidget* m_menuWidget;
    OptionsWidget* m_optionsWidget;

    NewView *m_newView;

    void createConnections();

private slots:
    void slotOpenPlayWidget();
    void slotOpenMenuWidget();
    void slotOpenOptionsWidget();

    void slotSetResolution(QString testResolution);
    void slotSetFullScreen();
};

#endif // WIDGET_H
