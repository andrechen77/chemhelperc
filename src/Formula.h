#pragma once

struct MolecularFormula;

struct Formula {
	virtual operator MolecularFormula() const = 0;
};
