#include "WaveForm.h"
#include <fstream>

void WaveForm::Parse(std::string_view Input, fast_vector<int16_t>& AudioSamples, WavHeader& Header)
{
	std::ifstream InputFile(Input.data(), std::ios::binary);

	InputFile.read((Binary)&Header, sizeof(WavHeader));
	AudioSamples.resize(Header.Time / sizeof(int16_t));
	InputFile.read((Binary)AudioSamples.data(), Header.Time);

	InputFile.close();
}

void WaveForm::Save(std::string_view Output, fast_vector<int16_t>& AudioSamples, WavHeader& Header)
{
	std::ofstream OutputFile(Output.data(), std::ios::binary | std::ios::out);

	OutputFile.write((Binary)&Header, sizeof(WavHeader));
	OutputFile.write((Binary)AudioSamples.data(), Header.Time);

	OutputFile.close();
}