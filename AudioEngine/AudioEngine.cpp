#include "AudioEngine.h"
#include "Effects.h"

void AudioEngine::Overlay(std::string_view Input, float Time)
{
	WaveForm::Parse(Input, m_AudioSamples, m_WavHeader);
	m_TotalSamples.add(ToSamples(Time), m_AudioSamples);
}

void AudioEngine::CreateSilence(float Time)
{
	m_TotalSamples.resize(ToSamples(Time));
}

void AudioEngine::Export(std::string_view Output)
{
	m_WavHeader.Time = m_TotalSamples.lenght() * sizeof(int16_t);
	m_WavHeader.SampleRate = 44100;

	Effects::NormalizeVolume(m_TotalSamples);
	WaveForm::Save(Output, m_TotalSamples, m_WavHeader);
}

size_t AudioEngine::ToSamples(float Time)
{
	return 44100 * Time * sizeof(int16_t);
}