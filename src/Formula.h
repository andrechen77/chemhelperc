#pragma once

struct MolecularFormula;

struct Formula {
	virtual MolecularFormula toMolecularFormula() const = 0;
};
