#pragma once
#include <fstream>
#include "fast_vector.h"
#include "WavHeader.h"

class AudioEngine //Currently only supports 16bit pcm 44100 sample rate wav files
{
	typedef char* Binary;
public:
	void Overlay(std::string_view AudioFile, float Time = 0, float Volume = 0);
	void CreateSilence(float Time);
	void Export(std::string_view Output);
private:
	void Parse(std::string_view AudioFile);
	void NormalizeVolume(float AdjustVolume);

	float GetNormalizedVolume();

	size_t ToSamples(float Time);
private:
	WavHeader m_LastWavHeader;
	fast_vector<int16_t> m_TotalSamples;
	fast_vector<int16_t> m_AudioSamples;
};
