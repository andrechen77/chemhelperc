#pragma once

#include "Element.h"

struct Atom {
	const Element &element;

	Atom(const Element &element);

	const Element &operator*() const;
};