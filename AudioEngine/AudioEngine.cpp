#include "AudioEngine.h"
#define GetHighestElement(Vector) *std::max_element(Vector.begin(), Vector.end())

void AudioEngine::Overlay(std::string_view AudioFile, float Time, float Volume)
{
	this->Parse(AudioFile);
	this->NormalizeVolume(Volume);

	m_TotalSamples.add(ToSamples(Time), m_AudioSamples);
}

void AudioEngine::CreateSilence(float Time)
{
	m_TotalSamples.allocate(ToSamples(Time));
}

void AudioEngine::Export(std::string_view Output)
{
	std::ofstream OutputFile(Output.data(), std::ios::binary | std::ios::out);

	m_LastWavHeader.LenghtInBytes = m_TotalSamples.capacity() * sizeof(int16_t);
	m_LastWavHeader.sampleRate = 44100; 

	OutputFile.write((Binary)&m_LastWavHeader, sizeof(WavHeader));
	OutputFile.write((Binary)m_TotalSamples.data(), m_LastWavHeader.LenghtInBytes);

	OutputFile.close();
}

void AudioEngine::Parse(std::string_view AudioFile)
{
	std::ifstream InputFile(AudioFile.data(), std::ios::binary);

	InputFile.seekg(0, std::ios::beg);
	InputFile.read((Binary)&m_LastWavHeader, sizeof(WavHeader));
	m_AudioSamples.resize(m_LastWavHeader.LenghtInBytes / sizeof(int16_t));
	InputFile.read((Binary)m_AudioSamples.data(), m_LastWavHeader.LenghtInBytes);

	InputFile.close();
}

void AudioEngine::NormalizeVolume(float AdjustVolume)
{
	float NormalizedVolume = this->GetNormalizedVolume();
	m_AudioSamples.multiply(AdjustVolume - NormalizedVolume);
}

float AudioEngine::GetNormalizedVolume()
{
	float SumOfSamples = 0;

	for (const auto& Sample : m_AudioSamples)
	{
		SumOfSamples += Sample * Sample;
	}

	float NormalizedSamples = SumOfSamples / (32767.f * 32767.f);

	float RMS = log10(NormalizedSamples / m_AudioSamples.lenght());

	return RMS;
}

size_t AudioEngine::ToSamples(float Time)
{
	return 44100 * Time * sizeof(int16_t);
}