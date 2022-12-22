#pragma once

#include "Element.h"
#include "Atom.h"
#include <set>
#include <iostream>
#include <optional>

class PeriodicTable {
	private:

	std::set<Element> elements;

	public:

	PeriodicTable(std::istream &input);

	const std::set<Element> &getElements() const;

	std::optional<Atom> getAtom(const std::string &symbol) const;
};