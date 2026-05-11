#include "Similarity.h"

#include <cmath>
#include <stdexcept>

float wavely::matching::dotProduct(const float* first, const float* second, std::size_t count) {
	if (first == nullptr) {
		throw std::invalid_argument("first pointer cannot be null.");
	};

	if (second == nullptr) {
		throw std::invalid_argument("second pointer cannot be null.");
	};

	// A vector with zero elements cannot produce a useful similarity score.
	if (count == 0) {
		throw std::invalid_argument("count must be greater than 0.");
	};


	float total = 0.0f;

	// Multiply matching elements and add them together.
	for(std::size_t i = 0; i < count; i++) {
		total += first[i] * second[i];
	};

	return total;
};

float wavely::matching::vectorMagnitude(const float* values, std::size_t count) {
	if (values == nullptr) {
		throw std::invalid_argument("values pointer cannot be null.");
	};

	if (count == 0) {
		throw std::invalid_argument("count must be greater than 0.");
	};


	float sumOfSquares = 0.0f;

	// Magnitude is based on the square root of the sum of squared values.
	for(std::size_t i = 0; i < count; i++) {
		sumOfSquares += values[i] * values[i];
	};

	return std::sqrt(sumOfSquares);
};

float wavely::matching::cosineSimilarity(const float* first, const float* second, std::size_t count) {
	// Here we compute the numerator of the cosine similarity formula.
	const float dot = wavely::matching::dotProduct(first, second, count);

	// Here we compute the lengths of both vectors.
	const float firstMagnitude = wavely::matching::vectorMagnitude(first, count);
	const float secondMagnitude = wavely::matching::vectorMagnitude(second, count);

	// If either vector is all zeros, then its magnitude is 0, and dividing by 0 is invalid, so we return 0 similarity.
	if ((firstMagnitude == 0.0f) || (secondMagnitude == 0.0f)) {
		return 0.0f;
	};

	return (dot / (firstMagnitude * secondMagnitude));
};
