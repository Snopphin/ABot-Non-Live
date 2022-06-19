#include "pch.h"
#include <random>

namespace Random
{
	int IntRandom(int Begin, int End)
	{
		std::uniform_int_distribution<int> Output(Begin, End);
		std::random_device Seed;
		std::mt19937 RandomEngine(Seed());

		return Output(RandomEngine);
	}
}