#pragma once

#include "Formula.h"
#include "Atom.h"
#include <map>

struct MolecularFormula : Formula {
	std::map<Atom, int> composition;

	MolecularFormula();

	MolecularFormula(std::map<Atom, int> &&composition);

	virtual MolecularFormula toMolecularFormula() const override;
};