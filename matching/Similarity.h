#pragma once

#include <cstddef>

namespace wavely::matching {

// Computes the dot product between two equal-length float arrays.
float dotProduct(const float* first, const float* second, std::size_t count);

// Computes the magnitude of a float vector. This tells us how large a vector is.
float vectorMagnitude(const float* values, std::size_t count);

// Computes cosine similarity between two equal-length float arrays.
//
// Cosine similarity means:
//     dotProduct(first, second) /
//     (vectorMagnitude(first) * vectorMagnitude(second))
//
// Result meaning:
//     1.0  = very similar direction
//     0.0  = unrelated/orthogonal direction
//    -1.0  = opposite direction
float cosineSimilarity(const float* first, const float* second, std::size_t count);
};
