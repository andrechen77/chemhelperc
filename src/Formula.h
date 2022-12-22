#pragma once

#include <iostream>

class MolecularFormula;

class Formula {
	public:

	virtual MolecularFormula toMolecularFormula() const = 0;

	/**
	 * inside parameter determines if the formula should act as if it is
	 * printed from within another formula
	*/
	virtual void printTo(std::ostream &o, bool inside) const = 0;

	friend std::ostream &operator<<(std::ostream &o, const Formula &f);
};
