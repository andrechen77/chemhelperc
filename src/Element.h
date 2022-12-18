#pragma once

#include <string>
#include <iostream>

struct Element {
    int atomicNumber;
    std::string symbol;
    std::string name;

    Element(int atomicNumber, const std::string &symbol, const std::string &name);

    friend bool operator<(const Element &a, const Element &b);

    friend std::ostream &operator<<(std::ostream &o, const Element &e);
};