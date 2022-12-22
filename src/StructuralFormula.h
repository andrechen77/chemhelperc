#pragma once

#include "Atom.h"
#include "Formula.h"
#include <vector>
#include <tuple>

struct StructuralFormula : Formula {
	std::vector<std::tuple<std::reference_wrapper<Formula>, int>> composition;

	StructuralFormula();

	StructuralFormula(const std::vector<std::tuple<std::reference_wrapper<Formula>, int>> &&composition);

	StructuralFormula(const std::string formulaString);

	virtual MolecularFormula toMolecularFormula() const override;

	virtual void printTo(std::ostream &o) const override;
};
