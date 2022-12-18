#pragma once

#include "Atom.h"
#include <map>

struct Formula {
    std::map<Atom, int> composition;

    Formula();

    Formula(const std::map<Atom, int> &&composition);

    Formula(const std::string formulaString);
};