#pragma once

#include <cstddef>

namespace wavely::dsp {
// Vad is a simple Voice Activity Detector.
//
// Its job is to look at a short frame of audio samples and decide whether that frame probably contains speech.
//
// This first version is energy based:
// - Compute the RMS energy of the frame.
// - Compare it against a threshold.
// - If RMS >= threshold, treat it as speech.
// - Otherwise, treat it as non-speech.

class Vad {
private:
	// This is the minimum RMS value needed for a frame to be considered speech.
	// A lower threshold makes the VAD more sensitive, a higher threshold less sensitive.
	float energyThreshold_;

public:
	// Creates a VAD with a chosen energy threshold.
	explicit Vad(float energyThreshold);

	// Returns the current energy threshold.
	float energyThreshold() const;

	// Changes the current energy threshold.
	void setEnergyThreshold(float energyThreshold);

	// This checks whether a frame probably contains speech.
	// Samples points to the first sample in the frame, sampleCount is the number of samples in the frame.
	// Returns true if RMS energy is high enough, false if the frame is probably silence/quiet noise.
	bool isSpeech(const float* samples, std::size_t sampleCount) const;
};
};
