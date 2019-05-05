#ifndef HERO_H
#define HERO_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPolygon>
#include <QTimer>


#include <windows.h>

class Hero : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Hero(QObject* parent = nullptr);
    ~Hero();
    void setRect(QRectF newRect);
    QRectF rect() const;

    void debugBundingRect();
public slots:
    void slotShot(bool shot);

signals:
    void signalBullet(QPointF start, QPointF end);
    void signalMouseTracking(bool);
private:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
    QPainterPath shape() const;
private slots:
    void slotGameTimer();
    void slotBulletTimer();
private:
    bool shot;
    bool m_trackingMouse;
    QTimer *gameTimer;
    QTimer *bulletTimer;
    QPointF target;

    void leftOffset(int offset);
    void rightOffset(int offset);
    void upOffset(int offset);
    void downOffset(int offset);
    void leftRotationOffset(int offset);
    void rightRotationOffset(int offset);

    bool onCollisionEnter(QString collider);

    QRectF m_heroRect;
    int m_speed;
    int m_angularVelocity;

    void setMouseTracking(bool);

    // QGraphicsItem interface
    bool m_activeMode;
protected:
    virtual void keyPressEvent(QKeyEvent *event);

    // QGraphicsItem interface
public:
    void advance(int phase);
};

#endif // HERO_H
