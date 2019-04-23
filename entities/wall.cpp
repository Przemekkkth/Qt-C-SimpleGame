#include "wall.h"
#include <QPainter>
#include "tools/config.h"

Wall::Wall() : QGraphicsItem ()
{
   m_entityRect = QRectF(0, 0, 64, 64);

   m_EntityPixmap = new QGraphicsPixmapItem(QPixmap(":/sprites/Wall1.png"),this);
   m_EntityPixmap->setTransformationMode(Qt::SmoothTransformation);
//   m_EntityPixmap->setX( m_entityRect.x() );
//   m_EntityPixmap->setY( m_entityRect.y() );
   m_EntityPixmap->boundingRect().setRect(m_entityRect.x(), m_entityRect.y(), m_entityRect.width(), m_entityRect.height());
}

void Wall::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /* widget*/)
{

}

void Wall::setEntityPosition(QRectF newRect)
{
    if( m_entityRect == newRect )
    {
        return;
    }


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
       m_EntityPixmap->setPixmap(QPixmap(":/sprites/Wall1.png"));
      m_EntityPixmap->update();
      prepareGeometryChange();
      update();
}

QRectF Wall::boundingRect() const
{
    return m_entityRect;
}

QPainterPath Wall::shape() const
{
    QPainterPath painterPath;
    painterPath.addRect(boundingRect() );
    return painterPath;
}

int Wall::type() const
{
    return WallType;
}
