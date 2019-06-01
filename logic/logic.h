#ifndef LOGIC_H
#define LOGIC_H

#include <QObject>

class Logic : public QObject
{
    Q_OBJECT
public:
    Logic(QObject* parent = 0);

    void setCountEnemiesToDestroy(int count);

    void reset();

    int m_initCountOfEnemies;
    int m_countOfEnemies;
    void checkCountOfEnemies();
signals:
    void signalNextLevel();

private:

public slots:

    void slotDecreaseEnemies();

};

#endif // LOGIC_H
