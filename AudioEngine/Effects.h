#pragma once
#include "WaveForm.h"

class Effects
{
public:
	static void NormalizeVolume(fast_vector<int16_t>& AudioSamples);
private:
	static float GetNormalizedVolume(fast_vector<int16_t>& AudioSamples);
};