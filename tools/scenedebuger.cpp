#include "scenedebuger.h"
#include <QPainter>

SceneDebuger::SceneDebuger(int rowCount, int columnCount, qreal tileWidth, qreal tileHeight) : QGraphicsRectItem ()
{
    m_rowCount = rowCount;
    m_columnCount = columnCount;
    m_tileWidth = tileWidth;
    m_tileHeight = tileHeight;
    setPos(0,0);
}

void SceneDebuger::paint(QPainter * painter, const QStyleOptionGraphicsItem * /*option*/, QWidget * /*widget*/)
{
    painter->setBrush(Qt::NoBrush);
    painter->setPen(Qt::red);

    for(int x = 0; x < m_rowCount; ++x)
        for(int y = 0; y < m_columnCount; ++y)
        {
            painter->drawRect(
                                       doubleToIntCoordinate ( y*m_tileWidth ) ,
                                       doubleToIntCoordinate ( x*m_tileHeight ),
                                       doubleToIntCoordinate ( m_tileWidth ),
                                       doubleToIntCoordinate ( m_tileHeight )
                               );
//            painter->drawText(y*m_tileWidth,
//                              x*m_tileHeight,
//                              m_tileWidth,
//                              m_tileHeight,
//                              Qt::AlignCenter,
//                              QString::number(y) + "x" + QString::number(x));
        }

}

QRectF SceneDebuger::boundingRect() const
{
    return QRectF(0,0, m_columnCount*m_tileWidth, m_rowCount*m_tileHeight );
}

void SceneDebuger::setRect(int rowCount, int columnCount, qreal tileWidth, qreal tileHeight)
{
    m_rowCount = rowCount;
    m_columnCount = columnCount;
    m_tileWidth = tileWidth;
    m_tileHeight = tileHeight;
}

QPainterPath SceneDebuger::shape() const
{
    return QPainterPath();
}

int SceneDebuger::doubleToIntCoordinate(double point)
{
    return  static_cast<int>(point);
}
