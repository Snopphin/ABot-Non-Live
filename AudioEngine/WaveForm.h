#pragma once

#include <string_view>
#include "FastVector.h"
#include "WavHeader.h"

class WaveForm
{
	typedef char* Binary;
public:
	static void Parse(std::string_view Input, fast_vector<int16_t>& AudioSamples, WavHeader& Header);
	static void Save(std::string_view Output, fast_vector<int16_t>& AudioSamples, WavHeader& Header);
};