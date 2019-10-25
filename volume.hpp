#pragma once

#include <array>
#include <string>
#include <cmath>

#include "maths.hpp"

using d = double;

namespace volume {

	d cube(d edge) {
		return std::round((std::pow(edge, 3)) * options::rounder) / options::rounder;
	}

	d rectangleCuboid(d length, d width, d height)
	{
		return std::round((length * width * height) * options::rounder) / options::rounder;
	}

	d cylinder(d radius, d height)
	{
		return std::round((maths::pi * std::pow(radius, 2) * height) * options::rounder) / options::rounder;
	}

	d cone(d radius, d height)
	{
		return std::round((maths::pi * std::pow(radius, 2) * height / 3) * options::rounder) / options::rounder;
	}

	d squareBasedPyramid(d side, d height)
	{
		return std::round((std::pow(side, 2) * height / 3) * options::rounder) / options::rounder;
	}

	d rectangleBasedPyramid(d length, d width, d height)
	{
		return std::round((length * width * height / 3) * options::rounder) / options::rounder;
	}

	d sphere(d radius)
	{
		return std::round(((4.0 / 3.0) * maths::pi * std::pow(radius, 3)) * options::rounder) / options::rounder;
	}

	std::array<std::string, 7> figures = { "Cube", "Rectangle cuboid", "Cylinder", "Cone", "Square based pyramid", "Rectangle based pyramid", "Sphere" };
	
	int figures_size = std::tuple_size<std::array<std::string, 7>>::value;

}