#include <iostream>

#include "Config.h"
#include "RingBuffer.h"

int main() {
	wavely::dsp::RingBuffer micHistory(wavely::config::MicHistorySamples);

	micHistory.push(0.10f);
	micHistory.push(0.20f);
	micHistory.push(0.30f);

	std::cout << "Wavely starting...\n";

	std::cout << "Ring Buffer Capacity: "
		  << micHistory.capacity()
		  << " samples\n";

	std::cout << "Current size: "
		  << micHistory.size()
		  << " samples\n";

	std::cout << "Newest sample: "
		  << micHistory.getFromNewest(0)
		  << "\n";

	std::cout << "One sample before newest: "
		  << micHistory.getFromNewest(1)
		  << "\n";
	
	return 0;
};
