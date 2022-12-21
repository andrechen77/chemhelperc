#pragma once

#include "Formula.h"
#include "Atom.h"
#include <map>

struct MolecularFormula : Formula {
	std::map<Atom, int> composition;

	virtual operator MolecularFormula() const override;
};