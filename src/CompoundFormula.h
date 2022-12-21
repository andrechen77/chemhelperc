#pragma once

#include "Atom.h"
#include "Formula.h"
#include <map>

struct CompoundFormula : Formula {
	std::map<Formula, int> composition;

	CompoundFormula();

	CompoundFormula(const std::map<Formula, int> &&composition);

	CompoundFormula(const std::string formulaString);
};
