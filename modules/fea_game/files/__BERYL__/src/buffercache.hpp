#pragma once
#include <fea/audio.hpp>
#include <memory>

struct BufferEntry
{
    fea::AudioSample sample;
    fea::Audio audio;
};

class BufferCache
{
    public:
        const fea::Audio& audio(const std::string& path);
    private:
        void cachePath(const std::string& path);
        std::unordered_map<std::string, std::unique_ptr<BufferEntry>> mBufferEntries;
};
