#ifndef NEWVIEW_H
#define NEWVIEW_H
#include <QGraphicsView>
#include <QResizeEvent>
class Scene;
class NewView : public QGraphicsView
{
    Q_OBJECT
public:
    NewView();
protected:
    void resizeEvent(QResizeEvent* e);
private slots:
    void slotSetMouseTracking(bool enabled);
    void slotNextLevel();
private:
    Scene *m_scene;
    void createConnections();

    qreal m_oldWidth;
    qreal m_oldHeight;


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
signals:
    void signalBackToMenu();
    void signalOpenPlayWidget();
};

#endif // NEWVIEW_H
