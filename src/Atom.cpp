#include "Atom.h"
#include "Element.h"
#include "MolecularFormula.h"

Atom::Atom(const Element &element) :
	element(element) {
}

const Element &Atom::operator*() const {
	return element;
}

MolecularFormula Atom::toMolecularFormula() const {
	return MolecularFormula({{*this, 1}});
}

bool Atom::operator<(const Atom &other) const {
	return this->element < other.element;
}

bool Atom::operator==(const Atom &other) const {
	return this->element == other.element;
}

void Atom::printTo(std::ostream &o) const {
	o << element.symbol;
}
