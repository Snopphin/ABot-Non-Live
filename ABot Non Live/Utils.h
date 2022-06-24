#pragma once

template <typename T>
static T ReadBinary(std::ifstream& File)
{
	T Output;
	File.read((char*)&Output, sizeof(T));

	return Output;
}

static size_t GetTotalBytes(std::ifstream& File)
{
	size_t TotalBytes = 0;

	File.seekg(0, std::ios::end);
	TotalBytes = File.tellg();
	File.seekg(0, std::ios::beg);

	return TotalBytes;
}