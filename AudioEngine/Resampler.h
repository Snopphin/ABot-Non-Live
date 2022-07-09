/**
 * Resampling algo from http://en.wikipedia.org/wiki/Lanczos_resampling
 * Adapted by / copyright Evan Raskob <evan@flkr.com>, 2009-2019
 * Free to use with attribution to all original authors / MIT License
 * https://opensource.org/licenses/MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

 // example use to downsample an array BIG of floats from 1024 points to another array SMALL with 128 points:		
 // Resample(BIG, 1024, SMALL, 128);

#include "fast_vector.h"

constexpr int FilterRadius = 3;

#define M_PI 3.14159265358979323846

static float Lanczos(int Radius, float x)
{
    if (x == 0.0f) 
        return 1.0f;

    if (x < -Radius || x > Radius)
        return 0.0f;

    float pi_x = x * M_PI;
    return Radius * sin(pi_x) * sin(pi_x / Radius) / (pi_x * pi_x);
}


static void Resample(fast_vector<int16_t>& Input, fast_vector<int16_t>& Output, float Speed)
{
    Output.resize(Speed > 1.0f ? Input.lenght() / Speed : Input.lenght() * Speed);

    float Factor = Speed > 1.0f ? Output.lenght() / (float)Input.lenght() : Input.lenght() / (float)Output.lenght();

    float Scale = std::min(Factor, 1.0f);
    float Support = FilterRadius / Scale;

    for (size_t Frame = 0; Frame != Output.lenght(); Frame++)
    {
        float Center = (Frame + 0.5f) / Factor;

        size_t Start = std::max(Center - Support + 0.5f, (float)0);
        size_t Stop = std::min(Center + Support + 0.5f, (float)Input.lenght());

        float Density = 0.0f;
        float s = Start - Center + 0.5f;

        Output[Frame] = 0;
        for (size_t x = 0; x != Stop - Start; x++, s++)
        {
            float Contribution = Lanczos(FilterRadius, s * Scale);
            Density += Contribution;

            Output[Frame] += Input[Start + x] * Contribution;
        }

        if (Density != 0.0f && Density != 1.0f)
        {
            /* Normalize. */
            Output[Frame] /= Density;
        }
    }
}