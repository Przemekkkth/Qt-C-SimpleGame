#include "hero.h"
#include <math.h>
#include <QDebug>
#include <QtMath>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <iostream>

#include "bluebackground.h"

//add Brick|Ground|Evil1|
#include "brick.h"
#include "evil1.h"
#include "bullet.h"
#include "ground.h"

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

Hero::Hero(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    setTransformOriginPoint(m_heroRect.center());
    m_speed = 2;
    m_angularVelocity = 2;
    setRotation(0);
    shot = false;// Set the starting triangle rotation
    gameTimer = new QTimer();   // Init game timer
    // Connect the signal from the timer and the slot game processing timer
    connect(gameTimer, &QTimer::timeout, this, &Hero::slotGameTimer);
    gameTimer->start(5);   // Start timer
    target = QPointF(0,0);  // Set the initial position of the cursor

//    m_trackingMouse = true;
//    bulletTimer = new QTimer();
//    connect(bulletTimer, &QTimer::timeout, this, &Hero::slotBulletTimer);
//    bulletTimer->start(1000/6);


    m_heroRect = QRectF(-12,-15,24,30);
}

Hero::~Hero()
{

}

QRectF Hero::boundingRect() const
{
    return QRectF(m_heroRect);
}

QPainterPath Hero::shape() const
{
    QPainterPath path;
//    QPolygon polygon;
////To more precision remove m_speed
//    int leftPoint = boundingRect().x() - m_speed;
//    int rightPoint = boundingRect().x() + boundingRect().width() + m_speed;
//    int bottomPoint =boundingRect().y() + boundingRect().height() + m_speed;
//    int topPoint = boundingRect().y() - m_speed;

//    QPoint leftVert = QPoint(leftPoint, bottomPoint);
//    QPoint rightVert = QPoint(rightPoint,bottomPoint);
//    QPoint midVert = QPoint(boundingRect().center().x(), topPoint);

//    polygon << midVert << leftVert << rightVert ;

//    path.addPolygon(polygon);
    path.addRect(boundingRect());

    return path;
}

void Hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* drawing triangle
     * */
    painter->setRenderHint(QPainter::Antialiasing);

//    painter->setPen(Qt::green);
//    painter->setBrush(Qt::yellow);
//    painter->drawPath(shape());

    QPolygon polygon;

    int lefrPoint = boundingRect().x();
    int rightPoint = boundingRect().x() + boundingRect().width();
    int bottomPoint =boundingRect().y() + boundingRect().height();
    int topPoint = boundingRect().y();

    QPoint leftVert = QPoint(lefrPoint, bottomPoint);
    QPoint rightVert = QPoint(rightPoint,bottomPoint);
    QPoint midVert = QPoint(boundingRect().center().x(), topPoint);


   // polygon << QPoint(0,-15) << QPoint(12,15) << QPoint(-12,15);
    polygon << midVert << leftVert << rightVert ;
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red);
    painter->drawPolygon(polygon);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}



void Hero::slotGameTimer()
{
    /* Move a triangle as a function of the buttons pressed
     * */

    if(GetAsyncKeyState('A')){
        leftOffset(m_speed);
        if(!onCollisionEnter("Background"))
        {
            rightOffset(m_speed*3);
        }

    }
    if(GetAsyncKeyState('D')){
        rightOffset(m_speed);
        if(!onCollisionEnter("Background"))
        {
           leftOffset(m_speed*3);
        }
    }
    if(GetAsyncKeyState('W')){
        upOffset(m_speed);
        if(!onCollisionEnter("Background"))
        {
            downOffset(m_speed*3);
        }
    }
    if(GetAsyncKeyState('S')){
        downOffset(m_speed);
        if(!onCollisionEnter("Background"))
        {
           upOffset(m_speed*3);
        }
    }

    if(GetAsyncKeyState(VK_LEFT))
    {
        setRotation(static_cast<int>(rotation()-m_angularVelocity)%360);
        if(!onCollisionEnter("Background"))
        {
           rightRotationOffset(m_angularVelocity);
        }
    }

    if(GetAsyncKeyState(VK_RIGHT))
    {
        setRotation(static_cast<int>(rotation()+m_angularVelocity)%360);
        if(!onCollisionEnter("Background"))
        {
           leftRotationOffset(m_angularVelocity);
        }
    }

}

void Hero::slotBulletTimer()
{
    // If shooting is enabled, the call signal to the creation of a bullet
    if(shot) emit signalBullet(mapToScene(boundingRect().center().x(), boundingRect().y() - m_speed), target);

}

void Hero::slotShot(bool shot)
{
    this->shot = shot;  // We get a permit or deny for shooting
}

void Hero::setRect(QRectF newRect)
{
    if(m_heroRect == newRect)
    {
        return;
    }
    prepareGeometryChange();
    setTransformOriginPoint(m_heroRect.center());
    m_heroRect = newRect;
}

QRectF Hero::rect() const
{
    return m_heroRect;
}

void Hero::debugBundingRect()
{
    qDebug() << "BoundingRect x: " << boundingRect().x() << " y: " << boundingRect().y() << " width: " << boundingRect().width()
             << " height: " << boundingRect().height();
}

void Hero::leftOffset(int offset)
{
    this->setX(this->x() - offset);
}

void Hero::rightOffset(int offset)
{
    this->setX(this->x() + offset);
}

void Hero::upOffset(int offset)
{
    this->setY(this->y() - offset);
}

void Hero::downOffset(int offset)
{
    this->setY(this->y() + offset);
}

void Hero::leftRotationOffset(int offset)
{
    setRotation(rotation() - offset);
}

void Hero::rightRotationOffset(int offset)
{
    setRotation(rotation() + offset);
}

bool Hero::onCollisionEnter(QString collider)
{
    //Calculate a type of collision
    int sumOfCollision = 0;
    QList<QGraphicsItem*> colliderList = collidingItems();
    for(int idx = 0; idx < colliderList.size(); ++idx)
    {
        if(collider == "Background")
        {
            //QGraphicsItem *item = qgraphicsitem_cast<BlueBackground*>(colliderList[idx]);
            if(qgraphicsitem_cast<BlueBackground*>(colliderList[idx]))
            {
                sumOfCollision += 1;
            }
            //Brick | Evil1 | Bullet |
            else if(qgraphicsitem_cast<Brick*>(colliderList[idx]) ||
                    qgraphicsitem_cast<Ground*>(colliderList[idx]) ||
                    qgraphicsitem_cast<Evil1*>(colliderList[idx]) ||
                    qgraphicsitem_cast<Bullet*>(colliderList[idx])
                    )
            {
                sumOfCollision += 1;
            }
        }
    }
    if(sumOfCollision == 1)
    {
        return true;
    }
    return false;
}

void Hero::setMouseTracking(bool enabled)
{
    if(m_trackingMouse == enabled){
        return;
    }
    m_trackingMouse = enabled;
    emit signalMouseTracking(m_trackingMouse);
}

void Hero::keyPressEvent(QKeyEvent *event)
{
    if(!m_activeMode)
        return;

    if(event->isAutoRepeat())
        return;

    if(event->key() == Qt::Key_Space)
    {
        Bullet *theBullet = new Bullet(mapToScene(boundingRect().center().x(), boundingRect().y() - m_speed), this, rotation());
        scene()->addItem(theBullet);
    }

    QGraphicsItem::keyPressEvent(event);
}

void Hero::advance(int phase)
{
    if(phase)
    {
        slotGameTimer();
        m_activeMode = true;
        qDebug() << "true";
    }
    else
    {
        m_activeMode = false;
    }
}
