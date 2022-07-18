#pragma once

struct WavHeader
{
    char RiffId[4];
    uint32_t HeaderChunkSize;
    char WaveId[4];
    char FormatChunkId[4];
    uint32_t FormatChunkSize;
    uint16_t CompressionCode;
    uint16_t NumberOfChannels;
    uint32_t SampleRate;
    uint32_t BitRate;
    uint16_t BlockAlign;
    uint16_t BitDepth;
    char DataChunkId[4];
    uint32_t Time;
};