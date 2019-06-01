#include "logic.h"
#include <QDebug>

Logic::Logic(QObject* parent) : QObject (parent)
{
    setCountEnemiesToDestroy(-1);
}

void Logic::setCountEnemiesToDestroy(int count)
{

    m_initCountOfEnemies = count;
    m_countOfEnemies = m_initCountOfEnemies;

}


void Logic::reset()
{
    m_countOfEnemies = m_initCountOfEnemies;
}

void Logic::checkCountOfEnemies()
{
    if(m_countOfEnemies == 0)
    {
        emit signalNextLevel();
    }
}

void Logic::slotDecreaseEnemies()
{
    --m_countOfEnemies;
    checkCountOfEnemies();
}
