#include "audioplayer.hpp"

AudioPlayer::AudioPlayer(fea::MessageBus& bus) :
    mBus(bus),
    mMusicHandle(0),
    mAudioHandle(0),
    mAudioFiles(
    {
        ////sounds
        //{"turn_page", "data/audio/TurnPage.ogg"},
        //{"queue_ding", "data/audio/BeepBep.ogg"},
        //{"pen", "data/audio/Pen.ogg"},
        //{"sigh", "data/audio/sigh.ogg"},
        //{"punch", "data/audio/Punch.ogg"},
        //{"rip1", "data/audio/rip1.ogg"},
        //{"rip2", "data/audio/rip2.ogg"},
        ////music
        //{"ambient_bank", "data/music/Ambankient.ogg"}
    }),
    mLoopMusic(false)
{
    subscribe(mBus, *this);
}

void AudioPlayer::update()
{
    mAudioPlayer.update();

    if(mLoopMusic)
    {
        if(mAudioPlayer.getStatus(mMusicHandle) == fea::EXPIRED)
        {
            mMusicHandle = mAudioPlayer.play(mFileStream);
        }
    }
}

void AudioPlayer::handleMessage(const PlayMusicMessage& message)
{
    FEA_ASSERT(mAudioFiles.count(message.name) > 0, "music file " + message.name + " not found!");
    mFileStream.openFile(mAudioFiles.at(message.name));
    mAudioPlayer.stop(mMusicHandle);
    mMusicHandle = mAudioPlayer.play(mFileStream);

    mLoopMusic = message.loop;
}

void AudioPlayer::handleMessage(const PlaySoundMessage& message)
{
    FEA_ASSERT(mAudioFiles.count(message.name) > 0, "audio file " + message.name + " not found!");

    mAudioPlayer.stop(mAudioHandle);
    mAudioHandle = mAudioPlayer.play(mBufferCache.audio(mAudioFiles.at(message.name)));
    mAudioPlayer.setLooping(mAudioHandle, message.loop);
}

void AudioPlayer::handleMessage(const StopSoundMessage& message)
{
    (void)message;
    mAudioPlayer.stop(mAudioHandle);
}
