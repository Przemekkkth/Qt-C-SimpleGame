#ifndef WALL_H
#define WALL_H
#include <QGraphicsItem>


class Wall : public QGraphicsItem
{
public:
    Wall();

public:
    void setEntityPosition(QRectF newRect);
protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
private:
    QRectF m_entityRect;
    QPixmap m_pixmap;
    QGraphicsPixmapItem *m_EntityPixmap;
    int type() const;
};

#endif // WALL_H
