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
	return MolecularFormula{}; // TODO
}
