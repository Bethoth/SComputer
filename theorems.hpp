#pragma once

#include <cmath>
#include <array>
#include <string>

#include "maths.hpp"

using d = double;

namespace theorems {

	d pythagore(std::string searched, d side1, d side2) {
		if (searched == "hypotenuse") {
			return std::round((std::sqrt(std::pow(side1, 2) + std::pow(side2, 2))) * options::rounder) / options::rounder;
		}
		else if (searched == "other") {
			if (maths::is_bigger(side1, side2)) {
				return std::round((std::sqrt(std::pow(side1, 2) - std::pow(side2, 2))) * options::rounder) / options::rounder;
			}
			else {
				return std::round((std::sqrt(std::pow(side2, 2) - std::pow(side1, 2))) * options::rounder) / options::rounder;
			}
		}
	}

	bool pythagore_inverse(d side1, d side2, d side3) {
		d bigger = 0;
		d else1 = 0;
		d else2 = 0;
		if (maths::is_bigger(side1, side2) && maths::is_bigger(side1, side3)) {
			bigger = side1;
			else1 = side2;
			else2 = side3;
		}
		else if (maths::is_bigger(side2, side1) && maths::is_bigger(side2, side3)) {
			bigger = side2;
			else1 = side1;
			else2 = side3;
		}
		else if (maths::is_bigger(side3, side1) && maths::is_bigger(side3, side2)) {
			bigger = side3;
			else1 = side1;
			else2 = side2;
		}

		return std::pow(bigger, 2) == std::pow(else1, 2) + std::pow(else2, 2);
	}

	std::array<std::string, 2> figures = { "Pythagore", "Pythagore inverse" };

	int figures_size = std::tuple_size<std::array<std::string, 2>>::value;

}