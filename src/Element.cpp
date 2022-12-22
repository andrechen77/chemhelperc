#include "Element.h"

Element::Element(int atomicNumber, const std::string &symbol, const std::string &name) :
	atomicNumber(atomicNumber), symbol(symbol), name(name) {
}

bool Element::operator<(const Element &other) const {
	return this->atomicNumber < other.atomicNumber;
}

std::ostream &operator<<(std::ostream &o, const Element &e) {
	o << e.atomicNumber << "\t" << e.symbol << "\t" << e.name;
	return o;
}

bool Element::operator==(const Element &other) const {
	return this->symbol == other.symbol;
}