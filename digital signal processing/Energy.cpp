#include "Energy.h"

#include <cmath>
#include <stdexcept>

float wavely::dsp::computeMeanSquare(const float* samples, std::size_t sampleCount) {
	if (samples == nullptr) {
		throw std::invalid_argument("Samples pointer cannot be null.");
	};

	if (sampleCount == 0) {
		throw std::invalid_argument("sampleCount must be greater than 0.");
	};

	
	float sumOfSquares = 0.0f;

	for(std::size_t i = 0; i < sampleCount; i++) {
		sumOfSquares += samples[i] * samples[i];	
	};

	// Averaging the squared values.
	return (sumOfSquares / static_cast<float>(sampleCount));
};

float wavely::dsp::computeRMS(const float* samples, std::size_t sampleCount) {
	return std::sqrt(computeMeanSquare(samples, sampleCount));
};

float wavely::dsp::computePeakAbs(const float* samples, std::size_t sampleCount) {
	if (samples == nullptr) {
		throw std::invalid_argument("Samples pointer cannot be null.");
	};

	if (sampleCount == 0) {
		throw std::invalid_argument("sampleCount must be greater than 0.");
	};


	float peak = 0.0f;

	for(std::size_t i = 0; i < sampleCount; i++) {
		const float absoluteSample = std::fabs(samples[i]);

		if (absoluteSample > peak) {
			peak = absoluteSample;
		};
	};

	return peak;
};
