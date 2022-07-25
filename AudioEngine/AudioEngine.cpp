#include "AudioEngine.h"

void AudioEngine::Overlay(std::string_view Input, float Time)
{
	SNDFILE* InputFile = sf_open(Input.data(), SFM_READ, &m_AudioInfo);

	if (InputFile == nullptr)
		return;

	m_AudioSamples.resize(m_AudioInfo.frames * m_AudioInfo.channels);

	sf_read_float(InputFile, m_AudioSamples.data(), m_AudioSamples.lenght());
	sf_close(InputFile);

	m_TotalSamples.add(ToSamples(Time), m_AudioSamples);
}

void AudioEngine::Export(std::string_view Output)
{
	SNDFILE* OutputFile = sf_open(Output.data(), SFM_WRITE, &m_AudioInfo);

	sf_write_float(OutputFile, m_TotalSamples.data(), m_TotalSamples.lenght());
	sf_write_sync(OutputFile);
	
	sf_close(OutputFile);
}

size_t AudioEngine::ToSamples(float Time)
{
	return m_AudioInfo.samplerate * Time * m_AudioInfo.channels;
}