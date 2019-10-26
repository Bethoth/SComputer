#pragma once

#include <array>
#include <string>
#include <cmath>
#include <optional>

#include "maths.hpp"

using std::stoi;

namespace physic {

	std::optional<double> voluminal_mass(std::string rho, std::string mass, std::string volume) {
		if (rho == "searched" && (mass != "searched" || volume != "searched")) {
			double int_mass = stoi(mass);
			double int_volume = stoi(volume);
			return std::round((int_mass / int_volume) * options::rounder) / options::rounder;
		}
		else if (mass == "searched" && (rho != "searched" || volume != "searched")) {
			double int_rho = stoi(rho);
			double int_volume = stoi(volume);
			return std::round((int_rho * int_volume) * options::rounder) / options::rounder;
		}
		else if (volume == "searched" && (rho != "searched" || mass != "searched")) {
			double int_rho = stoi(rho);
			double int_mass = stoi(mass);
			return std::round((int_mass / int_rho) * options::rounder) / options::rounder;
		}
		return {};
	}

	std::array<std::string, 1> figures = { "Voluminal mass" };

	int figures_size = std::tuple_size<std::array<std::string, 1>>::value;

}
