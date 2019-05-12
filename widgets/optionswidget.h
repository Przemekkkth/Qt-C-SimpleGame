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

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::Widget *ui;

signals:
    void signalBackClicked();
    void signalResolutionChanged(const QString resolution);
    void signalSetFullScreen();

};

#endif // WIDGET_H
