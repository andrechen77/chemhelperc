#pragma once

#include "Element.h"
#include "Formula.h"

struct Atom : Formula {
	const Element &element;

	Atom(const Element &element);

	const Element &operator*() const;

	virtual MolecularFormula toMolecularFormula() const override;

	friend bool operator<(const Atom &a, const Atom &b);

	friend bool operator==(const Atom &a, const Atom &b);
};