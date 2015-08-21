#pragma once
#include <fea/audio.hpp>
#include <fea/util.hpp>
#include "messages.hpp"
#include "buffercache.hpp"

class AudioPlayer :
    public fea::MessageReceiver<PlayMusicMessage, PlaySoundMessage, StopSoundMessage>
{
    public:
        AudioPlayer(fea::MessageBus& bus);
        void update();
        void handleMessage(const PlayMusicMessage& message) override;
        void handleMessage(const PlaySoundMessage& message) override;
        void handleMessage(const StopSoundMessage& message) override;
    private:
        fea::MessageBus& mBus;
        fea::AudioPlayer mAudioPlayer;
        fea::AudioFileStream mFileStream;
        fea::AudioHandle mMusicHandle;
        fea::AudioHandle mAudioHandle;
        std::unordered_map<std::string, std::string> mAudioFiles;
        BufferCache mBufferCache;
        bool mLoopMusic;
};
