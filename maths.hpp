#pragma once

#include <array>
#include <string>
#include <cmath>
#include <optional>

#include "options.hpp"

namespace maths {

	double add(double a, double b) {
		return std::round((a + b) * options::rounder) / options::rounder;
	}

	double subtract(double a, double b) {
		return std::round((a - b) * options::rounder) / options::rounder;
	}

	double multiply(double a, double b) {
		return std::round((a * b) * options::rounder) / options::rounder;
	}

	std::optional<double> divide(double a, double b) {
		if (b != 0) {
			return std::round((a / b) * options::rounder) / options::rounder;
		}
		return {};
	}

	int modulo(int a, int b) {
		return std::round((a % b) * options::rounder) / options::rounder;
	}


	bool is_lower(double a, double b) {
		return a < b;
	}

	bool is_bigger(double a, double b) {
		return a > b;
	}

	bool triangle_inequalities(double side1, double side2, double side3) {
		return side1 < (side2 + side3) && side2 < (side1 + side3) && side3 < (side1 + side2);
	}

	std::array<std::string, 2> comparisons = { "Inferiority test", "Superiority test" };
	int comparisons_size = std::tuple_size<std::array<std::string, 2>>::value;

	long double pi = 3.14159265358979323846L;

	std::array<std::string, 6> figures = { "Addition", "Subtraction", "Multiplication", "Division", "Modulo", "Comparison" };
	int figures_size = std::tuple_size<std::array<std::string, 6>>::value;

	std::array<std::string, 4> geometry_choices = { "Perimeter", "Area", "Volume", "Theorems" };
	int geometry_choices_size = std::tuple_size<std::array<std::string, 4>>::value;

}