#include "PeriodicTable.h"
#include "Atom.h"

#include <iostream>
#include <string>
#include <optional>

PeriodicTable::PeriodicTable(std::istream &input) :
	elements() {
	
	int atomicNumber;
	std::string symbol;
	std::string name;

	while (input) {
		input >> atomicNumber;
		input >> symbol;
		input >> name;
		elements.emplace(atomicNumber, symbol, name);
	}
}

const std::set<Element> &PeriodicTable::getElements() const {
	return elements;
}

std::optional<Atom> PeriodicTable::getAtom(const std::string &symbol) const {
	for (const Element &e : elements) {
		if (e.symbol == symbol) {
			return {e};
		}
	}
	return {};
}