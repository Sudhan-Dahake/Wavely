#include <iostream>

#include "Config.h"
#include "RingBuffer.h"
#include "Energy.h"
#include "Vad.h"
#include "Window.h"
#include "Similarity.h"

int main() {
        
	const float micFeatures[] = {
            1.0f,
            2.0f,
            3.0f
        };

        const float sameFeatures[] = {
            1.0f,
            2.0f,
            3.0f
        };

        const float differentFeatures[] = {
            3.0f,
            2.0f,
            1.0f
        };


	const std::size_t count = 3;

	
	std::cout << "Wavely starting...\n";

	std::cout << "Same Similarity: "
		  << wavely::matching::cosineSimilarity(micFeatures, sameFeatures, count)
		  << "\n";

	std::cout << "Different Similarity: "
		  << wavely::matching::cosineSimilarity(micFeatures, differentFeatures, count)
		  << "\n";

	return 0;
};
