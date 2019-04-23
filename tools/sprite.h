#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QPointF point, QObject *parent = nullptr);
    enum { Type = UserType + 1};
    int type() const;
private slots:
    void nextFrame();   /// Slot for turning frames

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QTimer *timer;  /// The timer for the animation of the explosion
    QPixmap *spriteImage;   /// QPixmap for the sprite with the explosion
    int currentFrame;
};

#endif // SPRITE_H
