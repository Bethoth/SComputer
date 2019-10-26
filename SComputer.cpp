#include "pch.h"

#include <iostream>
#include <cmath>
#include <Windows.h>
#include <array>
#include <string>
#include <vector>

#include "maths.hpp"
#include "perimeter.hpp"
#include "area.hpp"
#include "volume.hpp"
#include "theorems.hpp"
#include "physic.hpp"
#include "options.hpp"

void clear() {
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	//get the number of cells in the current buffer
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	//fill the entire buffer with spaces
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	//fill the entire buffer with the current colors and attributes
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	//move the cursor home
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

std::array<std::string, 4> main_menu_possibilities = { "Algebra", "Geometry", "Physic", "Options" };
int main_menu_possibilities_size = std::tuple_size<std::array<std::string, 4>>::value;

int main() {
	std::cout << "Welcome in the SComputer. Press Enter to access to menu." << std::endl;
	std::cin.ignore();

	clear();

	std::string restart = "y";
	while (restart == "y") {
		std::string choice = "0";

		clear();

		if (choice == "0") {
			std::cout << "Choose your way. (enter the number of the thing you need and press Enter)" << std::endl;
			for (int i = 0; i < main_menu_possibilities_size; ++i) {
				std::cout << i + 1 << ". " << main_menu_possibilities[i] << std::endl;
			}
		}

		std::cin >> choice;

		if (choice == "1") {
			clear();
			std::cout << "You chose " << main_menu_possibilities[0] << ". Choose your way." << std::endl;
			for (int i = 0; i < maths::figures_size; ++i) {
				std::cout << i + 1 << ". " << maths::figures[i] << std::endl;
			}
			std::cin >> choice;
			if (choice == "back") {
				choice = "0";
				restart = "y";
			}
			else {
				if (choice == "1") {
					clear();
					std::cout << "You chose " << maths::figures[0] << ". Enter the two numbers you want to add. (for example, enter 5 and 3 to get 8)" << std::endl;
					double a, b;
					std::cin >> a;
					std::cin >> b;
					std::cout << a << " + " << b << " = " << maths::add(a, b) << std::endl;
				}
				else if (choice == "2") {
					clear();
					std::cout << "You chose " << maths::figures[1] << ". Enter, at first, the number from which you want to subtract the other. (for example, enter 4 and 2 to get 2)" << std::endl;
					double a, b;
					std::cin >> a;
					std::cin >> b;
					std::cout << a << " - " << b << " = " << maths::subtract(a, b) << std::endl;
				}
				else if (choice == "3") {
					clear();
					std::cout << "You chose " << maths::figures[2] << ". Enter the two numbers you want to multiply. (for example, enter 4 and 2 to get 8)" << std::endl;
					double a, b;
					std::cin >> a;
					std::cin >> b;
					std::cout << a << " * " << b << " = " << maths::multiply(a, b) << std::endl;
				}
				else if (choice == "4") {
					clear();
					std::cout << "You chose " << maths::figures[3] << ". Enter, at first, the dividend and then, the divider. (for example, enter 12 and 4 to get 3)" << std::endl;
					double a, b;
					std::cin >> a;
					std::cin >> b;
					auto result = maths::divide(a, b);
					if (result.has_value()) {
						std::cout << a << " / " << b << " = " << *result << std::endl;
					}
					else {
						std::cout << "You cannot use 0 as divider." << std::endl;
					}
				}
				else if (choice == "5") {
					clear();
					std::cout << "You chose " << maths::figures[4] << ". Enter, at first, the dividend and then, the divider. (for example, enter 13 and 4 to get 1)" << std::endl;
					double a, b;
					std::cin >> a;
					std::cin >> b;
					std::cout << a << " % " << b << " = " << maths::modulo(a, b) << std::endl;
				}
				else if (choice == "6") {
					clear();
					std::cout << "You chose " << maths::figures[5] << ". Choose your way." << std::endl;
					for (int i = 0; i < maths::comparisons_size; ++i) {
						std::cout << i + 1 << ". " << maths::comparisons[i] << std::endl;
					}
					std::cin >> choice;
					if (choice == "1") {
						clear();
						std::cout << "You chose " << maths::comparisons[0] << ". Enter the two numbers, if the first you enter is lower, the app will say 'true', otherwise, it will say 'false'. (for example, enter 5 and 9, the app will say 'true')" << std::endl;
						double a, b;
						std::cin >> a;
						std::cin >> b;
						std::cout << std::boolalpha;
						std::cout << a << " < " << b << " is " << maths::is_lower(a, b) << "." << std::endl;
					}
					if (choice == "2") {
						clear();
						std::cout << "You chose " << maths::comparisons[1] << ". Enter the two numbers, if the first you enter is bigger, the app will say 'true', otherwise, it will say 'false'. (for example, enter 5 and 9, the app will say 'false')" << std::endl;
						double a, b;
						std::cin >> a;
						std::cin >> b;
						std::cout << std::boolalpha;
						std::cout << a << " > " << b << " is " << maths::is_bigger(a, b) << "." << std::endl;
					}
				}
			}
		}

		else if (choice == "2") {
			clear();
			std::cout << "You chose " << main_menu_possibilities[1] << ". Choose your way." << std::endl;
			for (int i = 0; i < maths::geometry_choices_size; ++i) {
				std::cout << i + 1 << ". " << maths::geometry_choices[i] << std::endl;
			}
			std::cin >> choice;
			if (choice == "1") {
				clear();
				std::cout << "You chose " << maths::geometry_choices[0] << ". Choose your way." << std::endl;
				for (int i = 0; i < perimeter::figures_size; ++i) {
					std::cout << i + 1 << ". " << perimeter::figures[i] << std::endl;
				}
				std::cin >> choice;
				if (choice == "1") {
					clear();
					std::cout << "You chose " << perimeter::figures[0] << ". Enter the length and the width of your figure." << std::endl;
					double length, width;
					std::cin >> length;
					std::cin >> width;
					std::cout << "P = 2 * " << length << " + 2 * " << width << " = " << perimeter::rectangle(length, width) << options::length_unit << std::endl;
				}
				else if (choice == "2") {
					clear();
					std::cout << "You chose " << perimeter::figures[1] << ". Enter the length of one side of your figure." << std::endl;
					double side;
					std::cin >> side;
					std::cout << "P = 4 * " << side << " = " << perimeter::square(side) << options::length_unit << std::endl;
				}
				else if (choice == "3") {
					clear();
					std::cout << "You chose " << perimeter::figures[2] << ". Enter the length of the radius of your figure." << std::endl;
					double radius;
					std::cin >> radius;
					std::cout << "P = 2 * pi * " << radius << " = " << perimeter::circle(radius) << options::length_unit << std::endl;
				}
				else if (choice == "4") {
					clear();
					std::cout << "You chose " << perimeter::figures[3] << ". Enter the length and the width of your figure." << std::endl;
					double length, width;
					std::cin >> length;
					std::cin >> width;
					std::cout << "P = 2 * " << length << " + 2 * " << width << " = " << perimeter::parallelogram(length, width) << options::length_unit << std::endl;
				}
				else if (choice == "5") {
					clear();
					std::cout << "You chose " << perimeter::figures[4] << ". Enter the lengths of the base and of the two other sides of your figure." << std::endl;
					double base, side1, side2;
					std::cin >> base;
					std::cin >> side1;
					std::cin >> side2;
					auto perimeter = perimeter::triangle(base, side1, side2);
					if (perimeter.has_value()) {
						std::cout << "P = " << base << " + " << side1 << " + " << side2 << " = " << *perimeter << options::length_unit << std::endl;
					}
					else {
						std::cout << "This triangle cannot exist. Learn about triangle inequalities." << std::endl;
					}
				}
				else if (choice == "6") {
					clear();
					std::cout << "You chose " << perimeter::figures[5] << ". Enter the lengths of each 4 sides of your figure." << std::endl;
					double base1, base2, side1, side2;
					std::cin >> base1;
					std::cin >> base2;
					std::cin >> side1;
					std::cin >> side2;
					std::cout << "P = " << base1 << " + " << base2 << " + " << side1 << " + " << side2 << " = " << perimeter::trapeze(base1, base2, side1, side2) << options::length_unit << std::endl;
				}
				else if (choice == "7") {
					clear();
					std::cout << "You chose " << perimeter::figures[6] << ". Enter the length of a side of your figure." << std::endl;
					double side;
					std::cin >> side;
					std::cout << "P = 4 * " << side << " = " << perimeter::diamond(side) << options::length_unit << std::endl;
				}
			}
			else if (choice == "2") {
				clear();
				std::cout << "You chose " << maths::geometry_choices[1] << ". Choose your way." << std::endl;
				for (int i = 0; i < area::figures_size; ++i) {
					std::cout << i + 1 << ". " << area::figures[i] << std::endl;
				}
				std::cin >> choice;
				if (choice == "1") {
					clear();
					std::cout << "You chose " << area::figures[0] << ". Enter the length and the width of your figure." << std::endl;
					double length, width;
					std::cin >> length;
					std::cin >> width;
					std::cout << "A = " << length << " * " << width << " = " << area::rectangle(length, width) << options::area_unit << std::endl;
				}
				else if (choice == "2") {
					clear();
					std::cout << "You chose " << area::figures[1] << ". Enter the length of one side of your figure." << std::endl;
					double side;
					std::cin >> side;
					std::cout << "A = " << side << "^2 = " << area::square(side) << options::area_unit << std::endl;
				}
				else if (choice == "3") {
					clear();
					std::cout << "You chose " << area::figures[2] << ". Enter the length of the radius of your figure." << std::endl;
					double radius;
					std::cin >> radius;
					std::cout << "A = pi * " << radius << "^2 = " << area::disk(radius) << options::area_unit << std::endl;
				}
				else if (choice == "4") {
					clear();
					std::cout << "You chose " << area::figures[3] << ". Enter the lengths of the base and of the height of your figure." << std::endl;
					double base, height;
					std::cin >> base;
					std::cin >> height;
					std::cout << "A = " << base << " * " << height << " = " << area::parallelogram(base, height) << options::area_unit << std::endl;
				}
				else if (choice == "5") {
					clear();
					std::cout << "You chose " << area::figures[4] << ". Enter the lengths of the base and of the height of your figure." << std::endl;
					double base, height;
					std::cin >> base;
					std::cin >> height;
					std::cout << "A = " << base << " * " << height << " / 2 = " << area::triangle(base, height) << options::area_unit << std::endl;
				}
				else if (choice == "6") {
					clear();
					std::cout << "You chose " << area::figures[5] << ". Enter the lengths of the two bases and of the height of your figure." << std::endl;
					double base1, base2, height;
					std::cin >> base1;
					std::cin >> base2;
					std::cin >> height;
					std::cout << "A = (" << base1 << " + " << base2 << ") * " << height << " / 2 = " << area::trapeze(base1, base2, height) << options::area_unit << std::endl;
				}
				else if (choice == "7") {
					clear();
					std::cout << "You chose " << area::figures[6] << ". Enter the lengths of the two diagonals of your figure." << std::endl;
					double diagonal1, diagonal2;
					std::cin >> diagonal1;
					std::cin >> diagonal2;
					std::cout << "A = " << diagonal1 << " * " << diagonal2 << " / 2 = " << area::diamond(diagonal1, diagonal2) << options::area_unit << std::endl;
				}
				else if (choice == "8") {
					clear();
					std::cout << "You chose " << area::figures[7] << ". Enter the length of the radius of your figure." << std::endl;
					double radius;
					std::cin >> radius;
					std::cout << "A = pi * 4 * " << radius << "^2 = " << area::sphere(radius) << options::area_unit << std::endl;
				}
				else if (choice == "9") {
					clear();
					std::cout << "You chose " << area::figures[8] << ". Enter the lengths of the radius and of the height of your figure." << std::endl;
					double radius, height;
					std::cin >> radius;
					std::cin >> height;
					std::cout << "A = pi * " << radius << " * sqrt(" << radius << "^2 + " << height << "^2) = " << area::cone(radius, height) << options::area_unit << std::endl;
				}
				else if (choice == "10") {
					clear();
					std::cout << "You chose " << area::figures[9] << ". Enter the length of one edge of your figure." << std::endl;
					double edge;
					std::cin >> edge;
					std::cout << "A = 6 * " << edge << "^2 = " << area::cube(edge) << options::area_unit << std::endl;
				}
				else if (choice == "11") {
					clear();
					std::cout << "You chose " << area::figures[10] << ". Enter the lengths of the length, of the width and of the height of your figure." << std::endl;
					double length, width, height;
					std::cin >> length;
					std::cin >> width;
					std::cin >> height;
					std::cout << "A = (2 * " << length << " * " << width << ") + (2 * " << length << " * " << height << ") + (2 * " << width << " * " << height << ") = " << area::rectangle_cuboid(length, width, height) << options::area_unit << std::endl;
				}
				else if (choice == "12") {
					clear();
					std::cout << "You chose " << area::figures[11] << ". Enter the lengths of the radius and of the height of your figure." << std::endl;
					double radius, height;
					std::cin >> radius;
					std::cin >> height;
					std::cout << "A = 2 * pi * " << radius << " * " << height << " = " << area::cylinder(radius, height) << options::area_unit << std::endl;
				}
				else if (choice == "13") {
					clear();
					std::cout << "You chose " << area::figures[12] << ". Enter the lengths of one base's side and of the height of your figure." << std::endl;
					double side, height;
					std::cin >> side;
					std::cin >> height;
					std::cout << "A = 4 * " << side << " * sqrt(" << height << "^2 + (" << side << " / 2)^2) / 2" << " = " << area::square_based_pyramid(side, height) << options::area_unit << std::endl;
				}
			}
			else if (choice == "3") {
				clear();
				std::cout << "You chose " << maths::geometry_choices[2] << ". Choose your way." << std::endl;
				for (int i = 0; i < volume::figures_size; ++i) {
					std::cout << i + 1 << ". " << volume::figures[i] << std::endl;
				}
				std::cin >> choice;
				if (choice == "1") {
					clear();
					std::cout << "You chose " << volume::figures[0] << ". Enter the length of one edge of your figure." << std::endl;
					double edge;
					std::cin >> edge;
					std::cout << "V = " << edge << "^3 = " << volume::cube(edge) << options::volume_unit << std::endl;
				}
				else if (choice == "2") {
					clear();
					std::cout << "You chose " << volume::figures[1] << ". Enter the length, the width and the height of your figure." << std::endl;
					double length, width, height;
					std::cin >> length;
					std::cin >> width;
					std::cin >> height;
					std::cout << "V = " << length << " * " << width << " * " << height << " = " << volume::rectangleCuboid(length, width, height) << options::volume_unit << std::endl;
				}
				else if (choice == "3") {
					clear();
					std::cout << "You chose " << volume::figures[2] << ". Enter the lengths of the radius and of the height of your figure." << std::endl;
					double radius, height;
					std::cin >> radius;
					std::cin >> height;
					std::cout << "V = pi" << " * " << radius << "^2 * " << height << " = " << volume::cylinder(radius, height) << options::volume_unit << std::endl;
				}
				else if (choice == "4") {
					clear();
					std::cout << "You chose " << volume::figures[3] << ". Enter the lengths of the radius and of the height of your figure." << std::endl;
					double radius, height;
					std::cin >> radius;
					std::cin >> height;
					std::cout << "V = pi" << " * " << radius << "^2 * " << height << " / 3 = " << volume::cone(radius, height) << options::volume_unit << std::endl;
				}
				else if (choice == "5") {
					clear();
					std::cout << "You chose " << volume::figures[4] << ". Enter the lengths of one base's side and of the height of your figure." << std::endl;
					double side, height;
					std::cin >> side;
					std::cin >> height;
					std::cout << "V = " << side << "^2 * " << height << " / 3 = " << volume::squareBasedPyramid(side, height) << options::volume_unit << std::endl;
				}
				else if (choice == "6") {
					clear();
					std::cout << "You chose " << volume::figures[5] << ". Enter the lengths of base's length and width and of the height of your figure." << std::endl;
					double length, width, height;
					std::cin >> length;
					std::cin >> width;
					std::cin >> height;
					std::cout << "V = " << length << " * " << width << " * " << height << " / 3 = " << volume::rectangleBasedPyramid(length, width, height) << options::volume_unit << std::endl;
				}
				else if (choice == "7") {
					clear();
					std::cout << "You chose " << volume::figures[6] << ". Enter the length of the radius of your figure." << std::endl;
					double radius;
					std::cin >> radius;
					std::cout << "V = 4/3 * pi * " << radius << "^3 = " << volume::sphere(radius) << options::volume_unit << std::endl;
				}
			}
			else if (choice == "4") {
				clear();
				std::cout << "You chose " << maths::geometry_choices[3] << ". Choose your way." << std::endl;
				for (int i = 0; i < theorems::figures_size; ++i) {
					std::cout << i + 1 << ". " << theorems::figures[i] << std::endl;
				}
				std::cin >> choice;
				if (choice == "1") {
					clear();
					std::cout << "You chose " << theorems::figures[0] << ". At first, enter 'hypotenuse' or 'other' depending on the side you are looking for. Then enter the lengths of the two other sides." << std::endl;
					std::string searched;
					double side1, side2;
					std::cin >> searched;
					std::cin >> side1;
					std::cin >> side2;
					double bigger, lower;
					if (maths::is_bigger(side1, side2)) {
						bigger = side1;
						lower = side2;
					}
					else {
						bigger = side2;
						lower = side1;
					}
					if (searched == "other") {
						std::cout << "Let ABC be a rectangular triangle in A. Let us admit that [AB] is the searched side. According to Pythagore's theorem, we have:"
							<< std::endl
							<< "BC^2 = AB^2 + AC^2"
							<< std::endl
							<< bigger << "^2 = " << "AB^2 + " << lower << "^2"
							<< std::endl
							<< "AB^2 = " << bigger << "^2 - " << lower << "^2"
							<< std::endl
							<< "AB^2 = " << std::pow(bigger, 2) - std::pow(lower, 2)
							<< std::endl
							<< "AB = " << "sqrt(" << std::pow(bigger, 2) - std::pow(lower, 2) << ")"
							<< std::endl
							<< "AB = " << theorems::pythagore(searched, side1, side2) << options::length_unit;
					}
					else if (searched == "hypotenuse") {
						std::cout << "Let ABC be a rectangular triangle in A. According to Pythagore's theorem, we have:"
							<< std::endl
							<< "BC^2 = AB^2 + AC^2"
							<< std::endl
							<< "BC^2 = " << side1 << "^2 + " << side2 << "^2"
							<< std::endl
							<< "BC^2 = " << std::pow(side1, 2) << " + " << std::pow(side2, 2)
							<< std::endl
							<< "BC^2 = " << std::pow(side1, 2) + std::pow(side2, 2)
							<< std::endl
							<< "BC = " << "sqrt(" << std::pow(side1, 2) + std::pow(side2, 2) << ")"
							<< std::endl
							<< "BC = " << theorems::pythagore(searched, side1, side2) << options::length_unit;
					}
				}
			}
		}
		
		else if (choice == "4") {
			clear();
			std::cout << "You chose " << main_menu_possibilities[3] << ". Choose your way." << std::endl;
			for (int i = 0; i < options::options_size; ++i) {
				std::cout << i + 1 << ". " << options::options[i] << std::endl;
			}
			std::cin >> choice;
			if (choice == "1") {
				clear();
				std::cout << "You chose " << options::options[0] << ". If you want information about this option, enter 1. If you want to set this option a different value, enter 2." << std::endl;
				std::cin >> choice;
				if (choice == "1") {
					std::cout << "This option represents the time elapsing between the display of the results and the time they disappear." << std::endl;
				}
				else if (choice == "2") {
					std::cout << "This option has to be set in miliseconds. For example, 3 seconds = 3000 miliseconds." << std::endl;
					std::cout << "Core value: " << 3000 << std::endl;
					std::cout << "Actual value: " << options::sleep_time << std::endl;
					std::cin >> options::sleep_time;
				}
			}
			else if (choice == "2") {
				clear();
				std::cout << "You chose " << options::options[1] << ". If you want information about this option, enter 1. If you want to set this option a different value, enter 2." << std::endl;
				std::cin >> choice;
				if (choice == "1") {
					std::cout << "This option represents the number of decimal digits to which the various results will be rounded." << std::endl;
				}
				else if (choice == "2") {
					std::cout << "This option has to be set like this : if you want 3 decimal digits, set this option to 1000,0 (but put a dot for the coma)." << std::endl;
					std::cout << "Core value: " << 1000.0 << std::endl;
					std::cout << "Actual value: " << options::rounder << std::endl;
					std::cin >> options::rounder;
				}
			}
			else if (choice == "3") {
				clear();
				std::cout << "You chose " << options::options[2] << ". Choose your way." << std::endl;
				for (int i = 0; i < options::units_size; ++i) {
					std::cout << i + 1 << ". " << options::units[i] << std::endl;
				}
				std::cin >> choice;
				if (choice == "1") {
					clear();
					std::cout << "You chose " << options::units[0] << "." << std::endl;
					std::cout << "Core value: cm" << std::endl;
					std::cout << "Actual value: " << options::length_unit << std::endl;
					std::cout << "Enter the unit you want the lengths to be set to." << std::endl;
					std::cin >> options::length_unit;
				}
				else if (choice == "2") {
					clear();
					std::cout << "You chose " << options::units[1] << "." << std::endl;
					std::cout << "Core value: cm^2" << std::endl;
					std::cout << "Actual value: " << options::area_unit << std::endl;
					std::cout << "Enter the unit you want the areas to be set to." << std::endl;
					std::cin >> options::area_unit;
				}
				else if (choice == "3") {
					clear();
					std::cout << "You chose " << options::units[2] << "." << std::endl;
					std::cout << "Core value: cm^3" << std::endl;
					std::cout << "Actual value: " << options::volume_unit << std::endl;
					std::cout << "Enter the unit you want the volumes to be set to." << std::endl;
					std::cin >> options::volume_unit;
				}
				else if (choice == "4") {
					clear();
					std::cout << "You chose " << options::units[3] << "." << std::endl;
					std::cout << "Core value: kg/cm^3" << std::endl;
					std::cout << "Actual value: " << options::voluminal_mass_unit << std::endl;
					std::cout << "Enter the unit you want the voluminal masses to be set to." << std::endl;
					std::cin >> options::voluminal_mass_unit;
				}
				else if (choice == "5") {
					clear();
					std::cout << "You chose " << options::units[4] << "." << std::endl;
					std::cout << "Core value: g" << std::endl;
					std::cout << "Actual value: " << options::mass_unit << std::endl;
					std::cout << "Enter the unit you want the masses to be set to." << std::endl;
					std::cin >> options::mass_unit;
				}
			}
		}

		else if (choice == "3") {
			clear();
			std::cout << "You chose " << main_menu_possibilities[2] << ". Choose your way." << std::endl;
			for (int i = 0; i < physic::figures_size; ++i) {
				std::cout << i + 1 << ". " << physic::figures[i] << std::endl;
			}
			std::cin >> choice;
			if (choice == "1") {
				clear();
				std::cout << "You chose " << physic::figures[0] << ". The input order is the following : rho ; mass ; volume. Enter the values you know and 'searched' for the value you don't know." << std::endl;
				std::string rho, mass, volume;
				std::cin >> rho;
				std::cin >> mass;
				std::cin >> volume;
				auto result = physic::voluminal_mass(rho, mass, volume);
				if (result.has_value()) {
					if (rho == "searched") {
						std::cout << "rho = m / V = " << mass << " / " << volume << " = " << *result << options::voluminal_mass_unit << std::endl;
					}
					else if (mass == "searched") {
						std::cout << "m = rho * V = " << rho << " * " << volume << " = " << *result << options::mass_unit << std::endl;
					}
					else if (volume == "searched") {
						std::cout << "V = m / rho = " << mass << " / " << rho << " = " << *result << options::volume_unit << std::endl;
					}
				}
				else {
					std::cout << "You entered too much 'searched' values." << std::endl;
				}
			}
		}
		
		Sleep(options::sleep_time);
		clear();
		std::cout << "Would you like to do an other computing? (y/n)" << std::endl;
		std::cin >> restart;
	}
}
