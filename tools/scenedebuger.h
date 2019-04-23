#ifndef SCENEDEBUGER_H
#define SCENEDEBUGER_H
#include <QGraphicsRectItem>

class SceneDebuger : public QGraphicsRectItem
{
public:
    SceneDebuger(int rowCount, int columnCount, qreal tileWidth, qreal tileHeight);
    void setRect(int rowCount, int columnCount, qreal tileWidth, qreal tileHeight);
protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    QRectF boundingRect() const;
    QPainterPath shape() const;
private:
    int m_rowCount;
    int m_columnCount;
    qreal m_tileWidth;
    qreal m_tileHeight;

    int doubleToIntCoordinate(double point);
};

#endif // SCENEDEBUGER_H
