#pragma once

#include <iostream>

struct MolecularFormula;

struct Formula {
	virtual MolecularFormula toMolecularFormula() const = 0;

	virtual void printTo(std::ostream &o) const = 0;

	friend std::ostream &operator<<(std::ostream &o, const Formula &f);
};
