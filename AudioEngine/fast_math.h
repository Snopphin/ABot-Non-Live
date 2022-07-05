#include <math.h>
#define M_PI 3.14159265358979323846

namespace fast_math
{
    static float sine(float x)
    {
        return 4.0f * (0.31830988618f * x * (1.0f - std::abs(0.31830988618f * x)));
    }
}