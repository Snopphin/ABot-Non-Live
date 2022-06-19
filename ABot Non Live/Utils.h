#pragma once

template <typename T>
T ReadBinary(std::ifstream& File)
{
	T Output;
	File.read((char*)&Output, sizeof(T));

	return Output;
}