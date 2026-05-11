#pragma once

#include <cstddef>

namespace wavely::dsp {
// This computes the mean square of an audio frame.
// Mean square means - square every sample, add all squared values, and divide by the number of samples.
// We do this because audio samples can be positive or negative, squaring removes the sign and measures signal strength.
float computeMeanSquare(const float* samples, std::size_t sampleCount);

// This computes the Root Mean Square (RMS) of an audio frame.
// Here RMS is a simple estimate of how loud/energetic a short chunk of audio is.
float computeRMS(const float* samples, std::size_t sampleCount);

// This finds the largest absolute sample value in an audio frame.
// This is different from RMS because it only looks at the strongest single sample, while RMS looks at the average energy of the whole frame.
float computePeakAbs(const float* samples, std::size_t sampleCount);
};
