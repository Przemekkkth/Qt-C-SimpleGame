#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QMap>

class QMediaPlayer;
class QMediaPlaylist;

class SoundManager : public QObject
{
public:
    SoundManager();
    ~SoundManager();
    void init();
    static SoundManager* instance();

    void playOneShotBGEffect(QUrl url);
    void playOneShotSoundEffect(QUrl url);
    void debugSources();
private:
    QMediaPlayer *m_backgroundEffectMediaPlayer;
    QMediaPlaylist *m_backgroundEffectMediaPlaylist;

    QMediaPlayer *m_soundEffectMediaPlayer;
    QMediaPlaylist *m_soundEffectMediaPlaylist;

    static SoundManager* s_instance;

    QMap<QUrl, int> m_bgEffectMap;
    QMap<QUrl, int> m_soundEffectMap;

    void addBackgroundEffectMedia(QUrl url);
    void addSoundEffectMedia(QUrl url);
};
#endif // SOUNDMANAGER_H
