#include "pch.h"
#include <random>

namespace Random
{
	int IntRandom(int Begin, int End)
	{
		std::random_device RandomDevice;
		std::mt19937 RandomEngine(RandomDevice());
		std::uniform_int_distribution UniformDistribution(Begin, End);

		return UniformDistribution(RandomEngine);
	}

	float FloatRandom(float Begin, float End)
	{
		std::random_device RandomDevice;
		std::mt19937 RandomEngine(RandomDevice());
		std::uniform_real_distribution UniformDistribution(Begin, End);

		return UniformDistribution(RandomEngine);
	}
}