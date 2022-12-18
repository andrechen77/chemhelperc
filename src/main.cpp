#include "Element.h"
#include "PeriodicTable.h"
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

int main() {
	std::cout << "Hello World from " << std::filesystem::current_path() << "!\n";

	std::ifstream pTableFile("pTable.txt");
	PeriodicTable pTable(pTableFile);

	for (const Element &e : pTable.elements) {
		std::cout << e << "\n";
	}

	std::string userInput;
	while (true) {
		std::cout << "Enter element symbol: ";
		std::cin >> userInput;
		if (userInput == "stop") {
			break;
		}

		std::optional<Atom> e = pTable.getAtom(userInput);
		if (e.has_value()) {
			std::cout << "Found element " << (**e) << "\n";
		} else {
			std::cout << "Found no matching element\n";
		}
	}
}