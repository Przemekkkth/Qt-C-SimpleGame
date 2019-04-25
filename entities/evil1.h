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
    void setPixmap(QPixmap pixmap);
    QPixmap pixmap() const;
    void hit(int damage);

    void setRect(QRectF newRect);
    QRectF rect() const;

    void setMovePoints(QList<QPointF>& points);

    void debugBundingRect();
    void createRoad();
private:
    QPixmap m_pixmap;
    int m_health;
    int m_maxHealth;
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

    // QGraphicsItem interface
public:
    void advance(int phase);
};

#endif // EVIL1_H
