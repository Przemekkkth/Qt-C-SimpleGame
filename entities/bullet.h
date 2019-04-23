#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPainter>


class Bullet : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Bullet(QPointF start, QGraphicsItem * hero, qreal rotation, QObject *parent = nullptr);
    ~Bullet();
signals:
    void hitOpponent(QGraphicsItem*);
public slots:

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QPainterPath shape() const;

private:
    QTimer* timerBullet;
    QGraphicsItem *hero;
private slots:
    void slotTimerBullet();
};

#endif // BULLET_H
