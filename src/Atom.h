#pragma once

#include "Element.h"
#include "Formula.h"

struct Atom : Formula {
	const Element &element;

	Atom(const Element &element);

	const Element &operator*() const;
};