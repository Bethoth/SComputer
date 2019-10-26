#pragma once

#include <array>
#include <string>

namespace options {

	unsigned long int sleep_time = 5000;

	double rounder = 1000.0;

	std::string length_unit = "cm";
	
	std::string area_unit = "cm^2";

	std::string volume_unit = "cm^3";

	std::string voluminal_mass_unit = "kg/cm^3";

	std::array<std::string, 4> units = { "Length", "Area", "Volume", "Voluminal mass" };

	int units_size = std::tuple_size<std::array<std::string, 4>>::value;

	std::array<std::string, 3> options = { "Sleep time", "Rounder", "Units" };

	int options_size = std::tuple_size<std::array<std::string, 3>>::value;

}
