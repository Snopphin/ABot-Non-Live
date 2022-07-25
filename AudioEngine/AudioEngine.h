#pragma once
#include <sndfile.h>
#include <string_view>

#include "fast_vector.h"

class AudioEngine
{
public:
	void Overlay(std::string_view Input, float Time = 0);
	void Export(std::string_view Output);
private:
	size_t ToSamples(float Time);
private:
	fast_vector<float> m_TotalSamples;
	fast_vector<float> m_AudioSamples;

	SF_INFO m_AudioInfo;
};