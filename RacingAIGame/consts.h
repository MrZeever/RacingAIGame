
#ifndef CONSTS_H
#define CONSTS_H

// Consts for game

struct consts {
	static constexpr int window_width{ 2560 };
	static constexpr int window_height{ 1440 };
	static constexpr float max_speed{ 40.0 };
	static constexpr float acc{ 0.4 };
	static constexpr float dec{ 0.3 };
	static constexpr float breaks{ 0.7 };
	static constexpr float turn_speed{ 0.06 };

};

#endif // CONSTS_H