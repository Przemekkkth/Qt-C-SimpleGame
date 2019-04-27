#ifndef OPTIONSWIDGET_H
#define OPTIONSWIDGET_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Widget;
}

class OptionsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptionsWidget(QWidget *parent = nullptr);
    ~OptionsWidget();

private slots:
    void on_otherButton_clicked();

    void on_keyboardButton_clicked();

    void on_backKButton_2_clicked();

    void on_backKButton_clicked();

private:
    Ui::Widget *ui;

signals:
    void signalBackClicked();

};

#endif // WIDGET_H
