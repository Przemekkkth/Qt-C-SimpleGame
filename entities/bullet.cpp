#include "bullet.h"
#include <QGraphicsScene>
#include "tools/sprite.h"
#include "bluebackground.h"
#include "tools/config.h"
#include "evil1.h"
#include "wall.h"
#include <QDebug>


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

Bullet::Bullet(QPointF start, QGraphicsItem * hero, qreal rotation, QObject *parent) : QObject(parent)
{
    this->hero = hero;
    setRotation(rotation);
    setPos(start);

    timerBullet = new QTimer();
    connect(timerBullet, &QTimer::timeout, this, &Bullet::slotTimerBullet);
    timerBullet->start(7);
}


QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, 2, 4);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/ , QWidget */*widget*/)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawRect(0, 0, 2, 4);
}

void Bullet::slotTimerBullet()
{
    setPos(mapToParent(0, -10));

    QList<QGraphicsItem *> foundItems = scene()->items(QPolygonF()
                                                           << mapToScene(0, 0)
                                                           << mapToScene(-1, -1)
                                                           << mapToScene(1, -1));


    foreach (QGraphicsItem *item, foundItems) {
        if (item == this || item == hero || item->type() == (UserType + 1)  )
        {
            continue;
        }
        //Evil1 || Ground || Brick
        else if(item->type() == GroundType || item->type() == BrickType || item->type() == WallType)
        {
            scene()->addItem(new Sprite(pos()));
            deleteLater();
        }
        else if(item->type() == Evil1Type)
        {
            qDebug() << "Hello";
            Evil1 *evilEnemy = qgraphicsitem_cast<Evil1*>(item);
            //connect()
            if(evilEnemy)
            {
                connect(this, &Bullet::hitOpponent, evilEnemy, &Evil1::slotShowHealth);
            }
            scene()->addItem(new Sprite(pos()));
            emit hitOpponent(item);
            deleteLater();
        }
    }

    if( x() < 0){
        deleteLater();
    }
    if(x() > scene()->width()){
        deleteLater();
    }
    if( y() < 0){
        deleteLater();
    }
    if( y() > scene()->height())
    {
        deleteLater();
    }
}

Bullet::~Bullet()
{

}

QPainterPath Bullet::shape() const
{
    return QPainterPath();
}
