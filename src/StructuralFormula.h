#pragma once

#include "Atom.h"
#include "Formula.h"
#include "PeriodicTable.h"
#include <vector>
#include <tuple>

class StructuralFormula : public Formula {
	private:

	std::vector<std::tuple<std::reference_wrapper<Formula>, int>> composition;

	public:

	StructuralFormula();

	StructuralFormula(const std::vector<std::tuple<std::reference_wrapper<Formula>, int>> &&composition);

	StructuralFormula(const PeriodicTable &pTable, const std::string &formulaString);

	virtual MolecularFormula toMolecularFormula() const override;

	virtual void printTo(std::ostream &o, bool inside) const override;
};
