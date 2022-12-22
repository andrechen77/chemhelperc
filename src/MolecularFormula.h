#pragma once

#include "Formula.h"
#include "Atom.h"
#include <map>
#include <iostream>

struct MolecularFormula : Formula {
	std::map<Atom, int> composition;

	MolecularFormula();

	MolecularFormula(std::map<Atom, int> &&composition);

	virtual MolecularFormula toMolecularFormula() const override;

	MolecularFormula &operator+=(const MolecularFormula &other);

	MolecularFormula operator+(const MolecularFormula &other) const;

	MolecularFormula &operator*=(int factor);

	MolecularFormula operator*(int factor) const;

	virtual void printTo(std::ostream &o) const override;
};