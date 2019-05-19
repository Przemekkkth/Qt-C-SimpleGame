#include "soundmanager.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

SoundManager* SoundManager::instance()
{
    if(s_instance == 0)
    {
        s_instance = new SoundManager();
    }
    return s_instance;
}

void SoundManager::playOneShotBGEffect(QUrl url)
{
    m_backgroundEffectMediaPlaylist->setCurrentIndex(m_bgEffectMap[url]);
    m_backgroundEffectMediaPlayer->setPlaylist(m_backgroundEffectMediaPlaylist);
    m_soundEffectMediaPlayer->setVolume(SDVolume());

    if (m_soundEffectMediaPlayer->state() == QMediaPlayer::PlayingState){
        m_soundEffectMediaPlayer->setPosition(0);
    }
    else if (m_soundEffectMediaPlayer->state() == QMediaPlayer::StoppedState){
        m_soundEffectMediaPlayer->play();
    }
}

void SoundManager::playOneShotSoundEffect(QUrl url)
{
    m_soundEffectMediaPlaylist->setCurrentIndex(m_soundEffectMap[url]);
    // play bulletsound
    if (m_soundEffectMediaPlayer->state() == QMediaPlayer::PlayingState){
        m_soundEffectMediaPlayer->setPosition(0);
    }
    else if (m_soundEffectMediaPlayer->state() == QMediaPlayer::StoppedState){
        m_soundEffectMediaPlayer->play();
    }

}

void SoundManager::debugSources()
{
    qDebug() << "backgroundEffect";
    QMapIterator<QUrl, int> bgIter(m_bgEffectMap);
    while (bgIter.hasNext()) {
        bgIter.next();
        qDebug() << "idx: " << bgIter.key() << " url: " << bgIter.value();
    }

    qDebug() << "soundEffect";
    QMapIterator<QUrl, int> sdIter(m_soundEffectMap);
    while (sdIter.hasNext()) {
        sdIter.next();
        qDebug() << "idx: " << sdIter.key() << " url: " << sdIter.value();
    }


}

void SoundManager::addBackgroundEffectMedia(QUrl url)
{
    m_bgEffectMap[url] = m_bgEffectMap.count();
    m_backgroundEffectMediaPlaylist->addMedia(QMediaContent(url));
}

void SoundManager::addSoundEffectMedia(QUrl url)
{
    m_soundEffectMap[url] = m_soundEffectMap.count();
    m_soundEffectMediaPlaylist->addMedia(QMediaContent(url));
}

void SoundManager::createConnections()
{
    connect(this, &SoundManager::BGVolumeChanged, [this](int newVal)
    {
        this->setBGVolume(newVal);
    });
    connect(this, &SoundManager::SDVolumeChanged, [this](int newVal)
    {
        this->setSDVolume(newVal);
    });
}

void SoundManager::init()
{
    m_backgroundEffectMediaPlayer = new QMediaPlayer(this);
    m_backgroundEffectMediaPlaylist = new QMediaPlaylist(this);
    m_backgroundEffectMediaPlaylist->setPlaybackMode(QMediaPlaylist::Loop);

    m_soundEffectMediaPlayer = new QMediaPlayer(this);
    m_soundEffectMediaPlaylist = new QMediaPlaylist(this);

    setBGVolume(50);
    setSDVolume(50);
    createConnections();
}

SoundManager* SoundManager::s_instance = 0;

SoundManager::SoundManager()
{
    init();
    m_backgroundEffectMediaPlayer->setPlaylist(m_backgroundEffectMediaPlaylist);
    m_soundEffectMediaPlayer->setPlaylist(m_soundEffectMediaPlaylist);
    addBackgroundEffectMedia(QUrl("qrc:/bgeffect/BG1Sounds.wav"));
    addSoundEffectMedia(QUrl("qrc:/soundeffect/Explosion3.wav"));
    addSoundEffectMedia(QUrl("qrc:/soundeffect/Laser_Shoot6.wav"));

}

SoundManager::~SoundManager()
{

}

void SoundManager::setBGVolume(int value)
{
    if(value == m_bgVolume)
    {
        return;
    }
    value = qBound(0, value, 100);
    m_bgVolume = value;
    emit BGVolumeChanged(value);
}

void SoundManager::setSDVolume(int value)
{
    if(value == m_sdVolume)
    {
        return;
    }

    value = qBound(0, value, 100);
    m_sdVolume = value;
    emit SDVolumeChanged(value);
}

int SoundManager::BGVolume() const
{
    return m_bgVolume;
}

int SoundManager::SDVolume() const
{
    return m_sdVolume;
}
