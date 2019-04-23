#ifndef BLUEBACKGROUND_H
#define BLUEBACKGROUND_H

#include <QGraphicsItem>

class BlueBackground : public QGraphicsItem
{
public:
    BlueBackground();
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
};

#endif // BLUEBACKGROUND_H
