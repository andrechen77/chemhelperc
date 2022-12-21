#pragma once

#include "Atom.h"
#include "Formula.h"
#include <vector>
#include <tuple>

struct StructuralFormula : Formula {
	std::vector<std::tuple<Formula, int>> composition;

	StructuralFormula();

	StructuralFormula(const std::vector<std::tuple<Formula, int>> &&composition);

	StructuralFormula(const std::string formulaString);
};
