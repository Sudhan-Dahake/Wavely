#pragma once

#include <cstddef>

namespace wavely::config {
	// Audio format used internally by digital signal processing code.
	// 16 kHz mono.
	inline constexpr int SampleRateHz = 16000;
	inline constexpr int NumChannels = 1;

	// We will process audio in small chunks which are called "frames".
	// We are choosing 20 ms for speech/audio analysis because its short enough for real-time response but long enough to contain useful speech structure.
	inline constexpr int FrameDurationMs = 20;

	// Number of samples in one frame.
	// At 16000 samples/second and 0.020 seconds, we get 16000 * 0.020 = 320 samples.
	inline constexpr int SamplesPerFrame = (SampleRateHz * FrameDurationMs) / 1000;

	// Here we define how much of the microphone audio we wanna keep.
	// This is the "temporary memory" of the recent speech.
	inline constexpr int MicHistorySeconds = 5;

	// Total samples needed to store "MicHistorySeconds" seconds of mono mic audio.
	inline constexpr std::size_t MicHistorySamples = static_cast<std::size_t>(SampleRateHz * MicHistorySeconds);

	// Echo delay search range.
	// Min and Max of when the voice is expected to echo back.
	inline constexpr int MinEchoDelayMs = 250;
	inline constexpr int MaxEchoDelayMs = 3000;

	// Ducking settings.
	// When we detect the echo, we reduce the meeting output volume.
	inline constexpr float NormalGain = 1.0f;
	inline constexpr float DuckedGain = 0.10f;

	// How quickly the volume changes.
	// Smaller attack = Faster ducking.
	// Larger release = smoother return to normal.
	inline constexpr int DuckAttackMs = 40;
	inline constexpr int DuckReleaseMs = 200;

	// Threshold.
	inline constexpr float EchoMatchThreshold = 0.75f;
}
