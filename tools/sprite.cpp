#include "sprite.h"

Sprite::Sprite(QPointF point, QObject *parent) : QObject(parent), QGraphicsItem()
{
    setPos(point);
    currentFrame = 0;
    spriteImage = new QPixmap(":/sprites/SpriteSheets.png");

    timer = new QTimer();
    connect(timer, &QTimer::timeout,
            this, &Sprite::nextFrame);
    timer->start(25);
}

void Sprite::nextFrame()
{
    currentFrame += 20;
    if(currentFrame >= 300)
    {
        deleteLater();
    }
    else
    {
        update(-10, -10, 20, 20);
    }
}

QRectF Sprite::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-10,-10, *spriteImage, currentFrame, 0, 20,20);
}

int Sprite::type() const {
    return Type;
}
