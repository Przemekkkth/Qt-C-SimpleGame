#include "evil1.h"
#include <QPainter>
#include <QTimer>
#include <QtMath>
#include <QGraphicsScene>

#include "tools/config.h"
#include <QDebug>

#include <windows.h>

int Evil1::type() const
{
    return Evil1Type;
}

Evil1::Evil1(QObject *parent) : QObject(parent), QGraphicsItem ()
{
    m_health = 30;
    m_maxHealth = m_health;
    m_entityRect = QRectF(0, 0, 64, 40);
    m_healthRect = QRectF(m_entityRect.x(), m_entityRect.y(), m_entityRect.width(), m_entityRect.height()/10 );

    m_pixmap = QPixmap(":/sprites/Enemy1.png");
    m_entityRect.setHeight(68);

    m_EntityPixmap = new QGraphicsPixmapItem(QPixmap(":/sprites/Enemy1.png"),this);
    m_EntityPixmap->setTransformationMode(Qt::SmoothTransformation);
    m_EntityPixmap->setX(m_entityRect.x());
    m_EntityPixmap->setY(m_entityRect.y() + m_healthRect.height());

    m_EntityPixmap->boundingRect().setHeight(m_entityRect.height() - m_healthRect.height());



//    m_points << QPointF(200,200) << QPointF(400,200); // move down-right then right
    m_pointIndex = 0;
//    m_dest = m_points[0];


    m_showHealth = false;

//    QTimer* timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &Evil1::slotMoveForward);
//    timer->start(10000/60);

}


QRectF Evil1::boundingRect() const
{
    return m_entityRect;
}

void Evil1::paint(QPainter* painter, const QStyleOptionGraphicsItem* /*option*/, QWidget */*widget*/)
{
    if(m_showHealth)
    {
        painter->setBrush(Qt::red);
        painter->drawRect( QRectF(m_entityRect.x(), m_entityRect.y(), m_entityRect.width(), m_entityRect.height()/10) );
    }
//    painter->setBrush(Qt::red);
//    painter->drawEllipse(shape().boundingRect());
}

QPainterPath Evil1::shape() const
{
    QPainterPath painterPath;
    qreal offset = 2*m_healthRect.height(); // set shape() below a health rect
    painterPath.addEllipse(m_entityRect.adjusted(offset/2, +offset, -offset/2, +offset));
    return painterPath;
}

void Evil1::hit(int damage)
{
    m_health -= damage;   // Reduce the target's health
    update( m_healthRect );    // Redraw target
    // If health is over, it will initiate the death of the target
    if(m_health <= 0) this->deleteLater();
}

void Evil1::setRect(QRectF newRect)
{
    if(m_entityRect == newRect)
    {
        return;
    }

    prepareGeometryChange();
    setTransformOriginPoint(m_entityRect.center());
    m_entityRect = newRect;
    qreal scaleX = newRect.width() / m_EntityPixmap->boundingRect().width();
    qreal scaleY = ( newRect.height() - m_healthRect.height() ) / newRect.width() / m_EntityPixmap->boundingRect().height();

    m_EntityPixmap->setScale( newRect.width() / m_EntityPixmap->boundingRect().width());
    m_EntityPixmap->setX(m_entityRect.x());
    m_EntityPixmap->setY(m_entityRect.y() + m_healthRect.height());
    m_EntityPixmap->boundingRect().setWidth(
                m_EntityPixmap->boundingRect().width() + scaleX
                );
    m_EntityPixmap->boundingRect().setHeight(
                m_EntityPixmap->boundingRect().height() + scaleY
                );
    update();
}

QRectF Evil1::rect() const
{
    return m_entityRect;
}

void Evil1::debugBundingRect()
{
    qDebug() << "boundingRect().x() " << boundingRect().x() << " boundingRect().y() " << boundingRect().y() << " boundingRect().width() " << boundingRect().width() << " boundingRect().height() " << boundingRect().height();
    qDebug() << "healthRect.x() " << m_healthRect.x() << " healthRect.y() " << m_healthRect.y() << " healthRect.width() " << m_healthRect.width() << " healthRect.height() " << m_healthRect.height();
    qDebug() << "evilPixmap->x() " << m_EntityPixmap->boundingRect().x() << " evilPixmap->y() " << m_EntityPixmap->boundingRect().y() << " evilPixmap->width() " << m_EntityPixmap->boundingRect().width() << " evilPixmap->height() " << m_EntityPixmap->boundingRect().height();
    qDebug() << "evilPixmap->x() " << m_EntityPixmap->boundingRect().x() << " evilPixmap->y() " << m_EntityPixmap->boundingRect().y() << " evilPixmap->width() " << m_EntityPixmap->boundingRect().width() << " evilPixmap->height() " << m_EntityPixmap->boundingRect().height();
}

void Evil1::createRoad()
{
    if( m_points.isEmpty() )
        return;

//    //static 4
//    QLineF line01(m_points[0], m_points[1]);
//    QLineF line12(m_points[1], m_points[2]);
//    QLineF line23(m_points[2], m_points[3]);
//    QLineF line03(m_points[0], m_points[3]);

//    scene()->addLine(line01);
//    scene()->addLine(line12);
//    scene()->addLine(line23);
//    scene()->addLine(line03);

}

void Evil1::setMovePoints(QList<QPointF>& points)
{
    if( !points.isEmpty() )
    {
        m_dest = points[0];
    }
    m_points = points;
}

void Evil1::slotMoveForward()
{
    if( m_points.isEmpty() )
        return;

    int STEP_SIZE = 2;
    QLineF ln(QPointF(pos().x() + m_entityRect.width()/2 , pos().y() + m_entityRect.height()/2 ), m_dest);


    if( ln.length() < ( STEP_SIZE + 1) ){
        m_pointIndex++;
        if( m_pointIndex >= m_points.size() )
        {
            m_pointIndex = 0;
        }

        m_dest = m_points[m_pointIndex];
    }


    double theta = ln.angle();//ln.angle();

    double dy = STEP_SIZE*qSin( qDegreesToRadians(theta) );
    double dx = STEP_SIZE*qCos( qDegreesToRadians(theta) );

    setPos(x() + dx, y() - dy);
}

void Evil1::advance(int phase)
{
    if(phase){
        slotMoveForward();
    }
}

void Evil1::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}
