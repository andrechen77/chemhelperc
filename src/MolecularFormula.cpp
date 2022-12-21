#include "MolecularFormula.h"

MolecularFormula::MolecularFormula() :
	composition() {
}

MolecularFormula::MolecularFormula(std::map<Atom, int> &&composition) :
	composition(std::move(composition)) {
}

MolecularFormula MolecularFormula::toMolecularFormula() const
{
	return *this;
}