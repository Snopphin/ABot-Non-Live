#pragma once
#include <fstream>
#include "fast_vector.h"
#include "WavHeader.h"
#define Silence 0

class AudioEngine //Currently only supports 16bit pcm 
{
	typedef char* Binary;
public:
	void Overlay(std::string_view AudioFile, float Time = 0, float AdjustVolume = 0.1);
	void CreateSilence(float Lenght);
	void Export(std::string_view Output);
private:
	void Parse(std::string_view AudioFile);
	void NormalizeVolume(float AdjustVolume);
	void SetVolume(float Volume);

	constexpr int16_t GetHighestSample();

	static float ToDecibels(int16_t Sample);
	static size_t ToSamples(float Time);
	static size_t To16Bytes(size_t Lenght);
private:
	WavHeader m_LastWavHeader;
	fast_vector<int16_t> m_TotalSamples;
	fast_vector<int16_t> m_AudioSamples;
};
