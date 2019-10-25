#pragma once

#include <array>
#include <string>

namespace options {

	unsigned long int sleep_time = 5000;

	double rounder = 1000.0;

	std::array<std::string, 2> options = { "Sleep time", "Rounder" };

	int options_size = std::tuple_size<std::array<std::string, 2>>::value;

}
