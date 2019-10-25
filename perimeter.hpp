#pragma once

#include <array>
#include <string>
#include <optional>

#include "maths.hpp"
#include "options.hpp"

namespace perimeter {

	double rectangle(double length, double width) {
		return std::round((2 * length + 2 * width) * options::rounder) / options::rounder;
	}

	double square(double side) {
		return std::round((4 * side) * options::rounder) / options::rounder;
	}

	double circle(double radius) {
		return std::round((maths::pi * radius * 2) * options::rounder) / options::rounder;
	}

	double parallelogram(double length, double width) {
		return std::round((2 * length + 2 * width) * options::rounder) / options::rounder;
	}

	std::optional<double> triangle(double base, double side1, double side2) {
		if (maths::triangle_inequalities(base, side1, side2)) {
			return std::round((base + side1 + side2) * options::rounder) / options::rounder;
		}
		return {};
	}

	double trapeze(double base1, double base2, double side1, double side2) {
		return std::round((base1 + base2 + side1 + side2) * options::rounder) / options::rounder;
	}

	double diamond(double side) {
		return std::round((side * 4) * options::rounder) / options::rounder;
	}

	std::array<std::string, 7> figures = { "Rectangle", "Square", "Circle", "Parallelogram", "Triangle", "Trapeze", "Diamond" };
	int figures_size = std::tuple_size<std::array<std::string, 7>>::value;
	
}