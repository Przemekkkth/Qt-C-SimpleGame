#include "ground.h"
#include <QGraphicsPixmapItem>
#include "tools/config.h"

Ground::Ground() : QGraphicsItem ()
{
    m_entityRect = QRectF(0, 0, 64, 64);

    int randVal = qrand() % 3 + 1;
    m_EntityPixmap = new QGraphicsPixmapItem(QPixmap(":/sprites/Ground" + QString::number(randVal) + ".png"),this);
    m_EntityPixmap->setTransformationMode(Qt::SmoothTransformation);
    m_EntityPixmap->setX( m_entityRect.x() );
    m_EntityPixmap->setY( m_entityRect.y() );
}

int Ground::type() const
{
    return GroundType;
}

void Ground::setEntityPosition(QRectF newRect)
{
    if( m_entityRect == newRect )
    {
        return;
    }

    prepareGeometryChange();
    m_entityRect = newRect;
       qreal scaleX = newRect.width() / m_EntityPixmap->boundingRect().width();
       qreal scaleY =  newRect.height()  / m_EntityPixmap->boundingRect().height();

       m_EntityPixmap->setScale( newRect.width() / m_EntityPixmap->boundingRect().width());
       m_EntityPixmap->setX(m_entityRect.x());
       m_EntityPixmap->setY( m_entityRect.y() );
       m_EntityPixmap->boundingRect().setWidth(
                   m_EntityPixmap->boundingRect().width() + scaleX
                   );
       m_EntityPixmap->boundingRect().setHeight(
                   m_EntityPixmap->boundingRect().height() + scaleY
                   );
       update();
}

QRectF Ground::boundingRect() const
{
    return m_entityRect;
}

QPainterPath Ground::shape() const
{
    QPainterPath painterPath;
    painterPath.addRect(boundingRect() );
    return painterPath;
}

void Ground::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget *widget)
{

}
