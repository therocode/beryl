#include "buffercache.hpp"

const fea::Audio& BufferCache::audio(const std::string& path)
{
    if(mBufferEntries.count(path) == 0)
    {
        cachePath(path);
    }

    auto& entry = mBufferEntries.at(path);

    return entry->audio;
}

void BufferCache::cachePath(const std::string& path)
{
    fea::AudioFile file;
    file.open(path);

    std::unique_ptr<BufferEntry> newEntry = std::unique_ptr<BufferEntry>(new BufferEntry);

    newEntry->sample.loadSampleData(file);
    newEntry->audio.setSample(newEntry->sample);

    mBufferEntries.emplace(path, std::move(newEntry));
}
