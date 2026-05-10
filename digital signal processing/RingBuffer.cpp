#include "RingBuffer.h"

#include <stdexcept>

wavely::dsp::RingBuffer::RingBuffer(std::size_t capacity) {
	if (capacity == 0) {
		throw std::invalid_argument("RingBuffer's capacity must be greater than 0.");
	};

	this->buffer_ = std::vector<float>(capacity, 0.0f);

	this->writeIndex_ = 0;

	this->size_ = 0;
};

std::size_t wavely::dsp::RingBuffer::capacity() const {
	return this->buffer_.size();
};

std::size_t wavely::dsp::RingBuffer::size() const {
	return this->size_;
};

bool wavely::dsp::RingBuffer::empty() const {
	return (this->size_ == 0);
};

void wavely::dsp::RingBuffer::clear() {
	this->writeIndex_ = 0;

	this->size_ = 0;

	for(float& sample : this->buffer_) {
		sample = 0.0f;
	};
};

void wavely::dsp::RingBuffer::push(float sample) {
	this->buffer_[this->writeIndex_] = sample;

	// The modulus operator makes the buffer circular.
	// If writeIndex reaches the buffer's size, then it wraps back to 0.
	this->writeIndex_ = (this->writeIndex_ + 1) % this->buffer_.size();

	if (this->size_ < this->buffer_.size()) {
		this->size_++;
	};
};

float wavely::dsp::RingBuffer::getFromNewest(std::size_t delaySamples) const {
	// Here we are making sure we are only reading samples that actually exist in the buffer.
	// E.g. - If size is 3, valid delaySamples values would be 0, 1, and 2 only.
	if (delaySamples >= this->size_) {
		throw std::out_of_range("delaySamples is outside the stored history.");
	};

	const std::size_t newestIndex = (this->writeIndex_ + this->buffer_.size() - 1) % this->buffer_.size();

	const std::size_t targetIndex = (newestIndex + this->buffer_.size() - delaySamples) % this->buffer_.size();

	return this->buffer_[targetIndex];
};
