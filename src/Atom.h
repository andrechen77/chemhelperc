#pragma once

#include "Element.h"
#include "Formula.h"

struct Atom : Formula {
	const Element &element;

	Atom(const Element &element);

	const Element &operator*() const;

	virtual MolecularFormula toMolecularFormula() const override;

	bool operator<(const Atom &other) const;

	bool operator==(const Atom &other) const;

	virtual void printTo(std::ostream &o) const override;
};