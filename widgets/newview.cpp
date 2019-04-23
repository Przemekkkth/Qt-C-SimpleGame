#include "newview.h"
#include "scenes/scene.h"
#include <QGraphicsItem>
#include <QDebug>

NewView::NewView() : QGraphicsView()
{
    //setMouseTracking(true);
    m_scene = new Scene();
    m_scene->setSceneRect(0,0, 800, 600);
    resize(800, 600);
    setScene(m_scene);

    m_oldWidth = width();
    m_oldHeight = width();
    m_scene->setInitEntitiesPosition(m_scene->tileRect().width(), m_scene->tileRect().height());


    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    createConnections();

    m_scene->getPlayer()->setFocus();

}

void NewView::resizeEvent(QResizeEvent*)
{

    m_scene->setSceneRect(0,
                                     0,
                                    width(),
                                    height() );

    fitInView(m_scene->sceneRect());

    foreach(QGraphicsItem *item, m_scene->items())
    {
         item->setPos(
                        item->pos().x() * width()/m_oldWidth,
                        item->pos().y() * height()/m_oldHeight);
    }

    m_scene->setEntitiesPosition();

    m_oldWidth = width();
    m_oldHeight = height();
}

void NewView::createConnections()
{
    //connect(m_scene, &Scene::signalFromHeroMouseTracking, this, &NewView::slotSetMouseTracking);
}

void NewView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace)
    {
        qDebug() << "Backspace";
        emit signalBackToMenu();
    }
    QGraphicsView::keyPressEvent(event);
}

void NewView::slotSetMouseTracking(bool enabled)
{
   // setMouseTracking(enabled);
}
