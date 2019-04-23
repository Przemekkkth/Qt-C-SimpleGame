#include "scene.h"
#include "entities/wall.h"
#include "entities/hero.h"
#include "entities/bullet.h"
#include "entities/evil1.h"
#include "entities/ground.h"
#include "entities/brick.h"
#include "entities/bluebackground.h"

#include "tools/scenedebuger.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <QDebug>

Scene::Scene(QObject */*parent*/) : QGraphicsScene ()
{

    initMedia();
    //Initialize level tiles
    // 4:3
    setColumns(40);
    setRows(30);

    playBackgroundMusic();
    m_debugMode = false;

    createEntities();
    setEntitiesPosition();


}



void Scene::setRect(int x0, int y0, int width, int height)
{
    QGraphicsScene::setSceneRect(x0, y0, width, height);
}

QRectF Scene::tileRect()
{
    QRectF retVal = QRectF(0,0, width()/ columns(), height() / rows());

    return retVal;
}

void Scene::createEntities()
{
//Create background
    m_background = new BlueBackground();
    addItem(m_background);
//Create walls
        //left
        for(int idx = 0; idx < rows(); ++idx)
        {
            Wall *oneWall = new Wall();
            m_leftWalls.push_back(oneWall);
            addItem(oneWall);
        }
        //right
        for(int idx = 0; idx < rows(); ++idx )
        {
            Wall *oneWall = new Wall();
            m_rightWalls.push_back(oneWall);
            addItem(oneWall);
        }
        //top
        for(int idx = 0; idx < columns(); ++idx)
        {
            Wall* oneWall = new Wall();
            m_topWalls.push_back(oneWall);
            addItem(oneWall);
        }
/////////////////////////////////////////////////////////////////////////////////


//Create game's Hero
    m_hero = new Hero();
    addItem(m_hero);
    m_hero->setPos(200, 200);
    m_hero->setFlag(QGraphicsItem::ItemIsFocusable);
    m_hero->setFocus();

/////////////////////////////////////////////////////////////////////////////////////////

//Create Bricks
    int vColumns = 10;
    int vRows = 18;
    for(int idx = 0; idx < (vColumns*vRows); ++idx)
    {
       Brick *oneBrick = new Brick();
       m_vertBricks.push_back(oneBrick);
       addItem(oneBrick);
    }

    int hColumns = 30;
    int hRows = 7;
    for(int idx = 0; idx < (hColumns*hRows); ++idx)
    {
       Brick *oneBrick = new Brick();
       m_horzBricks.push_back(oneBrick);
       addItem(oneBrick);
    }
/////////////////////////////////////////////////////////////////////////////////////////

//Create ground  [2xtileWidth, 2xtileHeight]
    for(int i = 0; i < columns()/2; ++i)
    {
        Ground* ground = new Ground();
        m_grounds.push_back(ground);
        addItem(ground);
    }
/////////////////////////////////////////////////////////////////////////////////////////

    //create enemies
    for(int idx = 0;  idx < 3; ++idx)
    {
        Evil1* evil1= new Evil1();
        m_enemiesVector.push_back(evil1);
        addItem(evil1);
   }
//Grid
    if(m_debugMode){
        m_sceneDebuger = new SceneDebuger(m_columns, m_rows, tileRect().width(), tileRect().height());
        addItem(m_sceneDebuger);
    }
}

void Scene::setEntitiesPosition()
{
    double tileWidth = tileRect().width();
    double tileHeight = tileRect().height();
//Background
    m_background->setEntityPosition(QRectF(0,0, width(), height() ));


//Walls
    //left
    for (int idx = 0; idx < m_leftWalls.size(); ++idx) {
        m_leftWalls[idx]->setEntityPosition( QRectF(0, idx*tileHeight, tileWidth, tileHeight) );
    }
    //right
    for(int idx = 0; idx < m_rightWalls.size(); ++idx){
        m_rightWalls[idx]->setEntityPosition( QRectF((columns()-1)*tileWidth, idx*tileHeight, tileWidth, tileHeight) );
    }
    //top
    for(int idx = 0; idx < m_topWalls.size(); ++idx)
    {
        m_topWalls[idx]->setEntityPosition( QRectF(idx*tileWidth, 0, tileWidth, tileHeight) );
    }

//Add Ground [2*tileWidth, 2*tileHeight]
    for(int idx = 0; idx < m_grounds.size(); ++idx)
    {
        m_grounds[idx]->setEntityPosition(QRectF( 2*idx* tileWidth , (rows()-2)*tileHeight, 2*tileWidth, 2*tileHeight) );
    }

//Add Bricks
    int vColumns = 10;
    int vRows = 18;
    int vIndex = 0;
    for(int x = 0; x < vColumns; ++x)
        for(int y = 0; y < vRows; ++y)
        {
            if(vIndex < m_vertBricks.size() )
                m_vertBricks[vIndex++]->setEntityPosition(QRectF(15*tileWidth + x*tileWidth,
                                                        6*tileHeight + y*tileHeight,
                                                        tileWidth,
                                                        tileHeight));
        }

    int hColumns = 30;
    int hRows = 7;
    int hIndex = 0;
    for(int x = 0; x < hColumns; ++x)
        for(int y = 0; y < hRows; ++y)
        {
            if(hIndex < m_horzBricks.size() )
                m_horzBricks[hIndex++]->setEntityPosition(QRectF(6*tileWidth + x*tileWidth,
                                                        11*tileHeight + y*tileHeight,
                                                        tileWidth,
                                                        tileHeight));
        }

//Hero
    m_hero->setRect(QRectF(m_hero->rect().x() ,
                    m_hero->rect().y() ,
                    tileWidth,
                    tileHeight));
//Enemies

    for(int idx = 0 ; idx < m_enemiesVector.size(); idx++)
    {
        m_enemiesVector[idx]->setRect(QRectF(m_enemiesVector[idx]->rect().x(),
                                             m_enemiesVector[idx]->rect().y(),
                                             2*tileWidth,
                                             2*tileHeight));
    }
//Create road for enemies
    m_enemiesVector[0]->setMovePoints(QList<QPointF>() << QPointF(  27*tileWidth, 3*tileHeight)
                                                                                      << QPointF(27*tileWidth, 9*tileHeight)
                                                                                      << QPointF(37*tileWidth, 9*tileHeight)
                                                                                      << QPointF(37*tileWidth, 3*tileHeight)
                                      );

    m_enemiesVector[1]->setMovePoints(QList<QPointF>() << QPointF( 37*tileWidth, 20*tileHeight)
                                                                                      << QPointF( 37*tileWidth, 26*tileHeight)
                                                                                      << QPointF( 26*tileWidth, 26*tileHeight)
                                                                                      << QPointF( 26*tileWidth, 20*tileHeight)
                                      );

    m_enemiesVector[2]->setMovePoints(QList<QPointF>() << QPointF(13*tileWidth, 20 * tileHeight)
                                                                                      << QPointF(13*tileWidth, 26*tileHeight)
                                                                                      << QPointF(2*tileWidth, 26*tileHeight)
                                                                                      << QPointF(2*tileWidth, 20*tileHeight)
                                      );

//Grid for see tiles
    if(m_debugMode){
        m_sceneDebuger->setRect(rows(), columns(), tileRect().width(), tileRect().height());
    }

    update();
}

int Scene::doubleToIntCoordinate(double point)
{
    return static_cast<int>(point);
}

void Scene::initMedia()
{
    m_shotSound = new QMediaPlayer(this);
    m_shotSound->setMedia(QUrl("qrc:/sounds/sounds/Laser_Shoot6.wav"));
    m_explosionEnemySound = new QMediaPlayer(this);
    m_explosionEnemySound->setMedia(QUrl("qrc:/sounds/sounds/Explosion3.wav"));
    m_backgroundSound = new QMediaPlayer(this);

    m_backgroundMusic = new QMediaPlaylist(this);
    m_backgroundMusic->addMedia(QUrl("qrc:/sounds/sounds/BG1Sounds.wav"));
    m_backgroundMusic->setPlaybackMode(QMediaPlaylist::Loop);
    m_backgroundSound->setVolume(20);
    m_backgroundSound->setPlaylist(m_backgroundMusic);



}

void Scene::slotBullet(QPointF start, QPointF end)
{
    Bullet *bullet = new Bullet(start, m_hero, 9);
    addItem(bullet);
    connect(bullet, &Bullet::hitOpponent, this, &Scene::slotHitTarget);

}

void Scene::slotCreateTarget()
{
 /*   Enemy* enemy = new Enemy();
    scene->addItem(enemy);

    enemy->setPos(qrand() % ((500 - 40 + 1) - 40) + 40,
                  qrand() % ((500 - 40 + 1) - 40) + 40);
    enemy->setZValue(-1);
    targets.append(enemy);
*/
}

//QList<QGraphicsItem *> Scene::targets;

void Scene::slotHitTarget(QGraphicsItem* item)
{
//    foreach(QGraphicsItem * targ, targets)
//    {
//        if(targ == item){
//            Enemy* target = qgraphicsitem_cast<Enemy*>(targ);
//            target->hit(randomBetween(1, 3));
//        }
    //    }
}


void Scene::setColumns(int number)
{
    if(m_columns == number)
    {
        return;
    }
    m_columns = number;
}

void Scene::setRows(int number)
{
    if(m_rows == number)
    {
        return;
    }
    m_rows = number;
}

int Scene::columns() const
{
    return m_columns;
}

int Scene::rows() const
{
    return  m_rows;
}

void Scene::playBackgroundMusic(bool enabled)
{
    if( enabled )
    {
        m_backgroundSound->play();
    }
    else
    {
        m_backgroundSound->stop();
    }
}

QGraphicsItem *Scene::getPlayer()
{
    return m_hero;
}

void Scene::setInitEntitiesPosition(qreal tileX, qreal tileY)
{
    m_hero->setPos( 12*tileX , 12*tileY);
    if(m_enemiesVector[0])
    {
        m_enemiesVector[0]->setPos(37*tileX, 3*tileY);
    }
    if(m_enemiesVector[1])
    {
        m_enemiesVector[1]->setPos( 37*tileX, 20*tileY);
    }
    if( m_enemiesVector[2] )
    {
        m_enemiesVector[2]->setPos(2*tileX, 26*tileY);
    }

}
