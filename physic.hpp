#pragma once

#include <array>
#include <string>
#include <cmath>
#include <optional>

#include "maths.hpp"

using std::stod;

namespace physic {

	const double G = 6.67e-11;

	std::optional<double> voluminal_mass(const std::string& rho, const std::string& mass, const std::string& volume) {
		const bool rho_is_searched = rho == "searched";
		const bool mass_is_searched = mass == "searched";
		const bool volume_is_searched = volume == "searched";
		if (rho_is_searched && !mass_is_searched && !volume_is_searched) {
			double int_mass = stod(mass);
			double int_volume = stod(volume);
			return std::round((int_mass / int_volume) * options::rounder) / options::rounder;
		}
		else if (mass_is_searched && !rho_is_searched && !volume_is_searched) {
			double int_rho = stod(rho);
			double int_volume = stod(volume);
			return std::round((int_rho * int_volume) * options::rounder) / options::rounder;
		}
		else if (volume_is_searched && !rho_is_searched && !mass_is_searched) {
			double int_rho = stod(rho);
			double int_mass = stod(mass);
			return std::round((int_mass / int_rho) * options::rounder) / options::rounder;
		}
		return {};
	}

	std::optional<double> gravitational_force(const std::string& F, const std::string& mass_a, const std::string& mass_b, const std::string& distance) {
		const bool F_is_searched = F == "searched";
		const bool mass_a_is_searched = mass_a == "searched";
		const bool mass_b_is_searched = mass_b == "searched";
		const bool distance_is_searched = distance == "searched";
		if (F_is_searched && !mass_a_is_searched && !mass_b_is_searched && !distance_is_searched) {
			double int_mass_a = stod(mass_a);
			double int_mass_b = stod(mass_b);
			double int_distance = stod(distance);
			return std::round((G * (int_mass_a * int_mass_b) / std::pow(int_distance, 2)) * options::rounder) / options::rounder;
		}
		else if (distance_is_searched && !mass_a_is_searched && !mass_b_is_searched && !F_is_searched) {
			double int_F = stod(F);
			double int_mass_a = stod(mass_a);
			double int_mass_b = stod(mass_b);
			return std::round(std::sqrt((G * int_mass_a * int_mass_b) / int_F) * options::rounder) / options::rounder;
		}
		else if (mass_a_is_searched && !distance_is_searched && !mass_b_is_searched && !F_is_searched) {
			double int_F = stod(F);
			double int_distance = stod(distance);
			double int_mass_b = stod(mass_b);
			return std::round(((int_F * std::pow(int_distance, 2)) / (G * int_mass_b)) * options::rounder) / options::rounder;
		}
		else if (mass_b_is_searched && !distance_is_searched && !mass_a_is_searched && !F_is_searched) {
			double int_F = stod(F);
			double int_distance = stod(distance);
			double int_mass_a = stod(mass_a);
			return std::round(((int_F * std::pow(int_distance, 2)) / (G * int_mass_a)) * options::rounder) / options::rounder;
		}
		return {};
	}

	std::array<std::string, 2> figures = { "Voluminal mass", "Gravitational force" };

	int figures_size = std::tuple_size<std::array<std::string, 2>>::value;

}
