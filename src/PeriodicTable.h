#pragma once

#include "Element.h"
#include "Atom.h"
#include <set>
#include <iostream>
#include <optional>

class PeriodicTable {
    public:

    std::set<Element> elements;

    PeriodicTable(std::istream &input);

    std::optional<Atom> getAtom(const std::string &symbol);
};