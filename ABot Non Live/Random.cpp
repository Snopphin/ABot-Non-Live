#include "pch.h"
#include <random>

namespace Random
{
	fast_io::ibuf_white_hole_engine s_RandomEngine;

	int IntRandom(int Begin, int End)
	{
		std::uniform_int_distribution UniformDistribution(Begin, End);

		return UniformDistribution(s_RandomEngine);
	}
	
	float FloatRandom(float Begin, float End)
	{
		std::uniform_real_distribution UniformDistribution(Begin, End);

		return UniformDistribution(s_RandomEngine);
	}
}