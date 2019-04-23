#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsItem>

class Brick : public QGraphicsItem
{
public:
    Brick();

public:
    void setEntityPosition(QRectF newRect);
    int type() const;
protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
private:
    QRectF m_entityRect;
    QPixmap m_pixmap;
    QGraphicsPixmapItem *m_EntityPixmap;
};

#endif // BRICK_H
