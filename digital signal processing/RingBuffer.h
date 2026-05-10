#pragma once

#include <cstddef>
#include <vector>

namespace wavely::dsp {

class RingBuffer {

private:
	// This is the actual storage for audio samples.
	// This is a ring buffer.
	std::vector<float> buffer_;

	// This is the index where the next pushed sample will be written.
	// When it reaches the end of the vector, it goes back to 0.
	std::size_t writeIndex_;

	// Number of valid samples currently stored.
	// Starts at 0 and grows until it reaches buffer.size().
	std::size_t size_;

public:
	// This creates a ring buffer with a fixed sample capacity.
	// It throws std::invalid_argument if capacity is 0.
	explicit RingBuffer(std::size_t capacity);

	// This returns the maximum number of samples the ring buffer can hold.
	std::size_t capacity() const;

	// This returns how many valid samples are currently stored in the buffer.
	std::size_t size() const;

	// This checks whether the buffer currently has no valid samples.
	bool empty() const;

	// This checks whether the buffer is completely full.
	bool full() const;

	// This removes all stored samples and resets the buffer.
	void clear();

	// This adds a new audio sample to the buffer.
	// If the buffer has free space, the sample is simply added.
	// If the buffer is already full it overwrites the oldest sample.
	// Takes input the audio sample to store.
	void push(float sample);

	// This reads a sample relative to the newest stored sample.
	// Takes input "delaySamples" - How far back to read from the newest sample.
	// A value of 0 for "delaySamples" means "give me the newest sample", whereas a value of 1 means "give me the sample before the newest".
	// Returns the requested sample, and throws std::out_of_range if "delaySamples" asks for a sample that is not currently stored.
	float getFromNewest(std::size_t delaySamples) const;
};
};
