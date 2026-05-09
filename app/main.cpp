#include <iostream>

#include "Config.h"

int main() {
	std::cout << "Wavely starting...\n";

	std::cout << "Sample rate: "
		  << wavely::config::SampleRateHz
		  << " Hz\n";

	std::cout << "Frame size: "
		  << wavely::config::SamplesPerFrame
		  << " sample\n";

	std::cout << "Mic history: "
		  << wavely::config::MicHistorySamples
		  << " samples\n";
	
	return 0;
};
