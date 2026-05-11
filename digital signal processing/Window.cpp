#include "Window.h"

#include <cmath>
#include <numbers>
#include <stdexcept>

std::vector<float> wavely::dsp::createHannWindow(std::size_t sampleCount) {
	if (sampleCount == 0) {
		throw std::invalid_argument("sampleCount must be greater than 0.");
	};

	std::vector<float> window(sampleCount, 0.0f);

	// Special Case.
	// If there is only one sample, there are no left/right edges to smooth, so we use 1.0f to keep that single sample unchanged.
	if (sampleCount == 1) {
		window[0] = 1.0f;

		return window;
	};

	// Hann Formula:
	//     w[n] = 0.5 * (1 - cos((2 * pi * n) / (N - 1)))
  
        // n is the current sample index.
        // N is the total number of samples in the window.
        //
        // This gives values near 0 at the start/end and near 1 in the middle.
	for(std::size_t n = 0; n < sampleCount; n++) {
		window[n] = static_cast<float>(0.5 * (1.0 - std::cos((2.0 * std::numbers::pi * static_cast<double>(n)) / (static_cast<double>(sampleCount - 1)))));
	};

	return window;
};

void wavely::dsp::applyWindow(const float* inputSamples, const float* window, float* outputSamples, std::size_t sampleCount) {
	if (inputSamples == nullptr) {
		throw std::invalid_argument("inputSamples pointer cannot be null.");
	};

	if (window == nullptr) {
		throw std::invalid_argument("window pointer cannot be null.");
	};

	if (outputSamples == nullptr) {
		throw std::invalid_argument("outputSamples pointer cannot be null.");
	};

	if (sampleCount == 0) {
		throw std::invalid_argument("sampleCount must be greater than 0.");
	};


	// Here we multiply every input sample by its matching window coefficient.
	for(std::size_t i = 0; i < sampleCount; i++) {
		outputSamples[i] = inputSamples[i] * window[i];
	};
};
