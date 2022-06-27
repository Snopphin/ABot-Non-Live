#include "AudioEngine.h"
#include "Resampler.h"
#define GetHighestElement(Vector) *std::max_element(Vector.begin(), Vector.end())
#define Silence 0

void AudioEngine::Overlay(std::string_view AudioFile, float Time, float Pitch, float AdjustVolume)
{
	this->Parse(AudioFile);
	this->NormalizeVolume(AdjustVolume);

	fast_vector<int16_t> PitchedSamples;
	Resample(m_AudioSamples, PitchedSamples, Pitch);

	m_TotalSamples.add(ToSamples(Time), PitchedSamples);
}

void AudioEngine::CreateSilence(float Length)
{
	m_TotalSamples.resize(ToSamples(Length), Silence);
}

void AudioEngine::Export(std::string_view Output)
{
	std::ofstream OutputFile(Output.data(), std::ios::binary | std::ios::out);

	m_LastWavHeader.LenghtInBytes = To16Bytes(m_TotalSamples.lenght());

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
	float PeakLoudness = ToDecibels(this->GetHighestSample());
	m_AudioSamples.multiply(AdjustVolume - PeakLoudness);
}

constexpr int16_t AudioEngine::GetHighestSample()
{
	return GetHighestElement(m_AudioSamples);
}

float AudioEngine::ToDecibels(int16_t Sample)
{
	return log10(Sample / float(INT16_MAX));
}

size_t AudioEngine::ToSamples(float Time)
{
	return To16Bytes(44100 * Time);
}

size_t AudioEngine::To16Bytes(size_t Lenght)
{
	return Lenght * sizeof(int16_t);
}