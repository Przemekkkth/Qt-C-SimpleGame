#include "bluebackground.h"
#include <QPainter>

BlueBackground::BlueBackground() : QGraphicsItem ()
{
   m_entityRect = QRectF(0, 0, 64, 64);

   m_EntityPixmap = new QGraphicsPixmapItem(QPixmap(":/sprites/BlueBackground.png"),this);
   m_EntityPixmap->setTransformationMode(Qt::SmoothTransformation);
//   m_EntityPixmap->setX( m_entityRect.x() );
//   m_EntityPixmap->setY( m_entityRect.y() );
   m_EntityPixmap->boundingRect().setRect(m_entityRect.x(), m_entityRect.y(), m_entityRect.width(), m_entityRect.height());
}

void BlueBackground::paint(QPainter * /*painter*/, const QStyleOptionGraphicsItem * /*option*/, QWidget * /* widget*/)
{
}

void BlueBackground::setEntityPosition(QRectF newRect)
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
     //  m_EntityPixmap->setPixmap(QPixmap(":/sprites/sprites/Wall1.png"));
      prepareGeometryChange();
      update();
}

QRectF BlueBackground::boundingRect() const
{
    return QRectF();
}

QPainterPath BlueBackground::shape() const
{
    QRectF shapeRect = QRectF(0,0,0,0);
    QPainterPath path;
    path.addRect(shapeRect);
    return path;
}
