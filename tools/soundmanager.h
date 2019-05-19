#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QObject>
#include <QMap>

class QMediaPlayer;
class QMediaPlaylist;

class SoundManager : public QObject
{
    Q_OBJECT
public:
    SoundManager();
    ~SoundManager();
    void init();
    static SoundManager* instance();

    void playOneShotBGEffect(QUrl url);
    void playOneShotSoundEffect(QUrl url);
    void debugSources();

    void setBGVolume(int value);
    void setSDVolume(int value);
    int BGVolume() const;
    int SDVolume() const;

signals:
    void BGVolumeChanged(int value);
    void SDVolumeChanged(int value);

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

    int m_bgVolume;
    int m_sdVolume;

    void createConnections();
};
#endif // SOUNDMANAGER_H
