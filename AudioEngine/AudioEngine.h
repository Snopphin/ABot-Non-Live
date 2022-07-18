#pragma once
#include "WaveForm.h"

class AudioEngine
{
public:
	void Overlay(std::string_view Input, float Time = 0);
	void CreateSilence(float Time);
	void Export(std::string_view Output);
private:
	size_t ToSamples(float Time);
private:
	fast_vector<int16_t> m_TotalSamples;
	fast_vector<int16_t> m_AudioSamples;
	
	WavHeader m_WavHeader;
};