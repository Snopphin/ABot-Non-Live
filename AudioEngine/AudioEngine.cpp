#include "AudioEngine.h"
#define GetHighestElement(Vector) *std::max_element(Vector.begin(), Vector.end())
#define Silence 0

void AudioEngine::Overlay(std::string_view AudioFile, float Time)
{
	this->Parse(AudioFile);
	m_TotalSamples.add(ToSamples(Time), m_AudioSamples);
}

void AudioEngine::CreateSilence(float Length)
{
	m_TotalSamples.resize(ToSamples(Length), Silence);
}

void AudioEngine::Export(std::string_view Output, float Volume)
{
	std::ofstream OutputFile(Output.data(), std::ios::binary | std::ios::out);

	NormalizeVolume(Volume);

	m_LastWavHeader.LenghtInBytes = To16Bytes(m_TotalSamples.lenght());
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
	m_TotalSamples.multiply(AdjustVolume - NormalizedVolume);
}

float AudioEngine::GetNormalizedVolume()
{
	float SumOfSamples = 0;

	for (auto& Sample : m_TotalSamples)
	{
		float NormalizedVolume = Sample / 32767.f;
		SumOfSamples += std::sqrt(NormalizedVolume * NormalizedVolume);
	}

	float RMS = log10(SumOfSamples / m_TotalSamples.lenght());

	return RMS;
}

size_t AudioEngine::ToSamples(float Time)
{
	return To16Bytes(44100 * Time);
}

size_t AudioEngine::To16Bytes(size_t Lenght)
{
	return Lenght * sizeof(int16_t);
}