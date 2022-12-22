#include "Element.h"
#include "PeriodicTable.h"
#include "chem_parser.h"
#include "MolecularFormula.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <filesystem>
#include <functional>

void printTable(const PeriodicTable &pTable) {
	for (const Element &e : pTable.elements) {
		std::cout << e << "\n";
	}
}

void processUserInputLoop(const PeriodicTable &pTable, const std::string &prompt, std::function<void(const PeriodicTable &, const std::string &)> processInput) {
	static const std::string sentinel = "end";
	
	std::string userInput;
	while (true) {
		std::cout << prompt << ": ";
		std::cin >> userInput;
		if (userInput == sentinel) {
			break;
		}
		processInput(pTable, userInput);
	}
}

void elementLookup(const PeriodicTable &pTable) {
	static auto processInput = [](const PeriodicTable &pTable, const std::string &userInput) {
		std::optional<Atom> e = pTable.getAtom(userInput);
		if (e.has_value()) {
			std::cout << "Found element\t" << (**e) << "\n";
		} else {
			std::cout << "Found no matching element\n";
		}
	};
	processUserInputLoop(pTable, "enter element symbol", processInput);
}

void parseFormulas(const PeriodicTable &pTable) {
	static auto processInput = [](const PeriodicTable &pTable, const std::string &userInput) {
		std::stringstream ss(userInput);
		std::string symbol;
		while (chem_parser::getSymbol(ss, symbol)) {
			std::cout << "next symbol: " << symbol << "\n";
		};
	};
	processUserInputLoop(pTable, "enter formula", processInput);
}

int main() {
	std::cout << "Hello World from " << std::filesystem::current_path() << "!\n";

	std::ifstream pTableFile("pTable.txt");
	PeriodicTable pTable(pTableFile);

	printTable(pTable);
	Atom H = *pTable.getAtom("H");
	Atom He = *pTable.getAtom("He");
	Atom Li = *pTable.getAtom("Li");
	Atom Cl = *pTable.getAtom("Cl");
	MolecularFormula a({{H, 1}, {Cl, 2}});
	MolecularFormula b({{H, 3}, {He, 7}});
	MolecularFormula c = a * 3;
	std::cout << c;
}