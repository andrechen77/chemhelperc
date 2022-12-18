#pragma once

#include "Element.h"
#include <set>
#include <iostream>

class PeriodicTable {
    public:

    std::set<Element> elements;

    PeriodicTable(std::istream &input);
};