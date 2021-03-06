#ifndef EVIL1_H
#define EVIL1_H

#include <QObject>
#include <QGraphicsItem>

class Evil1 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int type() const;
    explicit Evil1(QObject *parent = nullptr);
    void hit(int damage);

    void setRect(QRectF newRect);
    QRectF rect() const;

    void setMovePoints(QList<QPointF>& points);
    QList<QPointF> getMovePoints() const;

    void debugBundingRect();
    void createRoad();

    void setMaxHealth();
    void setShowHealth(bool enabled);
private:
    int m_health;
    int m_maxHealth;
    int m_speed;
    QRectF m_entityRect;

    qreal m_rotation;

    QRectF m_healthRect;
    QGraphicsPixmapItem *m_EntityPixmap;

    bool m_showHealth;

    QList<QPointF> m_points;
    QPointF m_dest;
    int m_pointIndex;

    void rotateToPoint(QPointF p);



protected:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
    QPainterPath shape() const;
private slots:
    void slotMoveForward();
public slots:
    void slotShowHealth();
    void slotTakeDamage();
    // QGraphicsItem interface
public:
    void advance(int phase);
signals:
    void signalEntityDestroyed();
};

#endif // EVIL1_H
