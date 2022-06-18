#pragma once

struct WavHeader
{
    char riffId[4];
    uint32_t bitDepth;
    char waveId[4];
    char formatChunkId[4];
    uint32_t formatChunkSize;
    uint16_t compressionCode;
    uint16_t numberOfChannels;
    uint32_t sampleRate;
    uint32_t bitRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char dataChunkId[4];
    uint32_t LenghtInBytes;
};