#include "Effects.h"

void Effects::NormalizeVolume(fast_vector<int16_t>& AudioSamples)
{
	float NormalizedVolume = GetNormalizedVolume(AudioSamples);
	AudioSamples.multiply(NormalizedVolume);
}

float Effects::GetNormalizedVolume(fast_vector<int16_t>& AudioSamples)
{
	float SumOfSamples = 0;

	for (const auto& Sample : AudioSamples)
	{
		float NormalizedSample = Sample / 32767.f;
		SumOfSamples += NormalizedSample * NormalizedSample;
	}

	float RMS = log10(SumOfSamples / AudioSamples.lenght());

	return RMS;
}