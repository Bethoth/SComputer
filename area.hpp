#pragma once

#include <cmath>
#include <array>
#include <string>

#include "maths.hpp"

using d = double;

namespace area {

	d rectangle(d length, d width) {
		return std::round((length * width) * options::rounder) / options::rounder;
	}

	d square(d side) {
		return std::round((std::pow(side, 2)) * options::rounder) / options::rounder;
	}

	d disk(d radius) {
		return std::round((std::pow(radius, 2) * maths::pi) * options::rounder) / options::rounder;
	}

	d parallelogram(d base, d height) {
		return std::round((base * height) * options::rounder) / options::rounder;
	}

	d triangle(d base, d height) {
		return std::round((base * height / 2) * options::rounder) / options::rounder;
	}

	d trapeze(d base1, d base2, d height) {
		return std::round(((base1 + base2) * height / 2) * options::rounder) / options::rounder;
	}

	d diamond(d diagonal1, d diagonal2) {
		return std::round((diagonal1 * diagonal2 / 2) * options::rounder) / options::rounder;
	}

	d sphere(d radius) {
		return std::round((std::pow(radius, 2) * maths::pi * 4) * options::rounder) / options::rounder;
	}

	d cone(d radius, d height) {
		return std::round((std::sqrt(std::pow(radius, 2) + std::pow(height, 2)) * maths::pi * radius) * options::rounder) / options::rounder;
	}

	d cube(d edge) {
		return std::round((std::pow(edge, 2) * 6) * options::rounder) / options::rounder;
	}

	d rectangle_cuboid(d length, d width, d height) {
		return std::round(((2 * length * width) + (2 * length * height) + (2 * width * height)) * options::rounder) / options::rounder;
	}

	d cylinder(d radius, d height) {
		return std::round((2 * maths::pi * radius * height) * options::rounder) / options::rounder;
	}

	d square_based_pyramid(d side, d height) {
		return std::round((side * 4 * std::sqrt(std::pow(height, 2) + std::pow((side / 2), 2)) / 2) * options::rounder) / options::rounder;
	}

	std::array<std::string, 13> figures = { "Rectangle", "Square", "Disk", "Parallelogram", "Triangle", "Trapeze", "Diamond", "Sphere", "Cone", "Cube", "Rectangle cuboid", "Cylinder", "Square based pyramid" };
	int figures_size = std::tuple_size<std::array<std::string, 13>>::value;

}