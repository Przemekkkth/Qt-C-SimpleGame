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
    //set health score, the best value is even. I set
    m_health = m_maxHealth = 30;
    m_speed = 2;
    m_maxHealth = m_health;
    m_pointIndex = 0;
    m_showHealth = false;

    //Entity geometry and set proportion
    m_entityRect = QRectF(0, 0, 64, 40);
    m_healthRect = QRectF(m_entityRect.x(), m_entityRect.y(), m_entityRect.width(), m_entityRect.height()/10 );
    m_entityRect.setHeight(68);

    //Set pixmap
    m_EntityPixmap = new QGraphicsPixmapItem(QPixmap(":/sprites/Enemy1.png"),this);
    m_EntityPixmap->setTransformationMode(Qt::SmoothTransformation);
    m_EntityPixmap->setX(m_entityRect.x());
    m_EntityPixmap->setY(m_entityRect.y() + m_healthRect.height());
    m_EntityPixmap->boundingRect().setHeight(m_entityRect.height() - m_healthRect.height());
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
        painter->drawRect( QRectF(m_entityRect.x(), m_entityRect.y(), m_entityRect.width() * m_health/m_maxHealth, m_entityRect.height()/10) );
    }
}

QPainterPath Evil1::shape() const
{
    QPainterPath painterPath;
    // set shape() below a health rect
    qreal offset = 2*m_healthRect.height();
    painterPath.addEllipse(m_entityRect.adjusted(offset/2, +offset, -offset/2, +offset));
    return painterPath;
}

void Evil1::hit(int damage)
{
    // Reduce the target's health
    m_health -= damage;
    // Redraw target
    update( m_healthRect );
    if(m_health <= 0)
    {
        //deleteLater();
        scene()->removeItem(this);
        emit signalEntityDestroyed();
    }
}

void Evil1::setRect(QRectF newRect)
{
    if(m_entityRect == newRect)
    {
        return;
    }

    qreal scaleX = newRect.width() / m_EntityPixmap->boundingRect().width();
    qreal scaleY =  newRect.height()  / m_EntityPixmap->boundingRect().height();
    setTransformOriginPoint(m_entityRect.center());

    m_entityRect = newRect;
    m_EntityPixmap->setScale( scaleX );

    prepareGeometryChange();
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
}

void Evil1::setMaxHealth()
{
    m_health = m_maxHealth;
}

void Evil1::setShowHealth(bool enabled)
{
    m_showHealth = enabled;
}

void Evil1::setMovePoints(QList<QPointF>& points)
{
    if( !points.isEmpty() )
    {
        m_dest = points[0];
    }
    m_points = points;
}

QList<QPointF> Evil1::getMovePoints() const
{
    return m_points;
}

void Evil1::slotMoveForward()
{
    if( m_points.isEmpty() )
    {
        return;
    }

    QLineF ln(QPointF(pos().x() + m_entityRect.width()/2 , pos().y() + m_entityRect.height()/2 ), m_dest);

    if( ln.length() < ( m_speed * 2) )
    {
        m_pointIndex++;
        if( m_pointIndex >= m_points.size() )
        {
            m_pointIndex = 0;
        }
        m_dest = m_points[m_pointIndex];
    }

    double theta = ln.angle();//ln.angle();
    double dy = m_speed*qSin( qDegreesToRadians(theta) );
    double dx = m_speed*qCos( qDegreesToRadians(theta) );
    setPos(x() + dx, y() - dy);
}

void Evil1::slotShowHealth()
{
    m_showHealth = true;
    QTimer *tempTimer = new QTimer();
    tempTimer->singleShot(2000, this, [this](){m_showHealth = false;});
}

void Evil1::slotTakeDamage()
{
    if(sender())
    {
        hit(10);
    }
}

void Evil1::advance(int phase)
{
    if(phase)
    {
        slotMoveForward();
    }
}

void Evil1::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}
