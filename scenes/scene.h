#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Wall;
class Hero;
class Evil1;
class SceneDebuger;
class Ground;
class Brick;
class BlueBackground;
class QMediaPlayer;
class QMediaPlaylist;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

    void setRect(int x0, int y0, int width, int height);

    void setEntitiesPosition();
    void setInitEntitiesPosition(qreal tileX, qreal tileY);

    enum{Rows = 20, Columns = 20};
    QRectF tileRect();

    void setColumns(int number);
    void setRows(int number);
    int columns() const;
    int rows() const;

    void playBackgroundMusic(bool enabled = true);

    QGraphicsItem* getPlayer();
private:
    //Entities
    QVector<Brick* > m_horzBricks;
    QVector<Brick* > m_vertBricks;
    Wall *m_horzPaddle, *m_vertPaddle;

    BlueBackground* m_background;

    Hero *m_hero;
    QVector<Ground *> m_grounds;
    QVector<Wall *> m_leftWalls;
    QVector<Wall *> m_rightWalls;
    QVector<Wall *> m_topWalls;
    //Create Entities

    void createEntities();

    int doubleToIntCoordinate(double point);

    QVector<Evil1*> m_enemiesVector;


    int m_rows;
    int m_columns;

    //To debug
    SceneDebuger *m_sceneDebuger;
    bool m_debugMode;

    QMediaPlayer *m_shotSound, *m_explosionEnemySound;
    QMediaPlayer *m_backgroundSound;
    QMediaPlaylist *m_backgroundMusic;

    void initMedia();
private slots:
    void slotBullet(QPointF start, QPointF end);
    void slotCreateTarget();
    void slotHitTarget(QGraphicsItem *item);



    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);

    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
