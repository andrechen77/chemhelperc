#include "Element.h"

Element::Element(int atomicNumber, const std::string &symbol, const std::string &name) :
	atomicNumber(atomicNumber), symbol(symbol), name(name) {
}

bool operator<(const Element &a, const Element &b) {
	return a.atomicNumber < b.atomicNumber;
}

std::ostream &operator<<(std::ostream &o, const Element &e) {
	o << e.atomicNumber << "\t" << e.symbol << "\t" << e.name;
	return o;
}