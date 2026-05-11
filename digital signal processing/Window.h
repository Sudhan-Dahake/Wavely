#pragma once

#include <cstddef>
#include <vector>

namespace wavely::dsp {
// This creates Hann window coefficients.
//
// A Hann window is a list of multiplier values between 0 and 1.
// The values start near 0, rise toward 1 in the middle and fall back near 0 at the end.
//
// Before FFT, we will multiply each audio sample by the matching window value, this smooths the edges of the frame.
std::vector<float> createHannWindow(std::size_t sampleCount);

// Applies a window to an audio frame.
//
// inputSamples points to the original audio frame.
// window points to the window coefficients.
// outputSamples points to where the windowed samples will be written.
// sampleCount tells us how many samples to process.
void applyWindow(const float* inputSamples, const float* window, float* outputSamples, std::size_t sampleCount);
};
