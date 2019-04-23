#ifndef GROUND_H
#define GROUND_H
#include <QGraphicsItem>
#include <QPixmap>

class Ground : public QGraphicsItem
{
public:
    Ground();
    int type() const;
public:
    void setEntityPosition(QRectF newRect);
private:
    QRectF m_entityRect;
    QPixmap m_pixmap;
    QGraphicsPixmapItem *m_EntityPixmap;
protected:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget);
};

#endif // GROUND_H
