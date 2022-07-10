#pragma once
#include <fstream>
#include "fast_vector.h"
#include "WavHeader.h"

class AudioEngine //Currently only supports 16bit pcm 44100 sample rate wav files
{
	typedef char* Binary;
public:
	void Overlay(std::string_view AudioFile, float Time = 0);
	void CreateSilence(float Lenght);
	void Export(std::string_view Output, float Volume = 1);
private:
	void Parse(std::string_view AudioFile);
	void NormalizeVolume(float AdjustVolume);

	float GetNormalizedVolume();

	static size_t ToSamples(float Time);
	static size_t To16Bytes(size_t Lenght);
private:
	WavHeader m_LastWavHeader;
	fast_vector<int16_t> m_TotalSamples;
	fast_vector<int16_t> m_AudioSamples;
};
