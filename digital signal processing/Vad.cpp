#include "Vad.h"
#include "Energy.h"

#include <stdexcept>

wavely::dsp::Vad::Vad(float energyThreshold) {
	if (energyThreshold < 0.0f) {
		throw std::invalid_argument("energyThreshold must be non-negative.");
	};

	this->energyThreshold_ = energyThreshold;
};

float wavely::dsp::Vad::energyThreshold() const {
	return this->energyThreshold_;
};

void wavely::dsp::Vad::setEnergyThreshold(float energyThreshold) {
	if (energyThreshold < 0.0f) {
		throw std::invalid_argument("energyThreshold must be non-negative.");
	};

	this->energyThreshold_ = energyThreshold;
};

bool wavely::dsp::Vad::isSpeech(const float* samples, std::size_t sampleCount) const {
	const float rms = wavely::dsp::computeRMS(samples, sampleCount);

	return (rms >= this->energyThreshold_);
};
