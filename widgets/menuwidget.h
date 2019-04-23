#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class MenuWidget;
}

class MenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

private:
    Ui::MenuWidget *ui;
    void createStylesheets();
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent* event);

private slots:
    void on_optionsButton_clicked();
    void on_playButton_clicked();
    void on_quitButton_clicked();
signals:
    void signalPlayClicked();
    void signaleOptionsClicked();
};

#endif // WIDGET_H
