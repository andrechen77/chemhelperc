#pragma once

#include "Element.h"
#include "Formula.h"

class Atom : public Formula {
	private:

	const Element &element;

	public:

	Atom(const Element &element);

	const Element &getElement() const;

	virtual MolecularFormula toMolecularFormula() const override;

	bool operator<(const Atom &other) const;

	bool operator==(const Atom &other) const;

	virtual void printTo(std::ostream &o, bool inside) const override;
};