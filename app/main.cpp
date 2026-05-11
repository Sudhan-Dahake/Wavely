#include <iostream>

#include "Config.h"
#include "RingBuffer.h"
#include "Energy.h"
#include "Vad.h"

int main() {
        const float quietFrame[] = {
            0.001f,
            -0.001f,
            0.002f,
            -0.002f
        };

        const float speechLikeFrame[] = {
            0.10f,
            -0.15f,
            0.20f,
            -0.12f
        };


	const std::size_t quietFrameSize = sizeof(quietFrame) / sizeof(quietFrame[0]);

	const std::size_t speechLikeFrameSize = sizeof(speechLikeFrame) / sizeof(speechLikeFrame[0]);

	wavely::dsp::Vad vad(0.02f);


	std::cout << "Wavely starting...\n";

	std::cout << "Is Quiet Frame Speech? "
		  << vad.isSpeech(quietFrame, quietFrameSize)
		  << "\n";

	std::cout << "is Speech-like Frame Speech? "
		  << vad.isSpeech(speechLikeFrame, speechLikeFrameSize)
		  << "\n";

	return 0;
};
