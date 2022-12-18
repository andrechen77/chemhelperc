#include "PeriodicTable.h"

#include <iostream>
#include <string>

PeriodicTable::PeriodicTable(std::istream &input) :
    elements() {
    
    int atomicNumber;
    std::string symbol;
    std::string name;

    while (input) {
        input >> atomicNumber;
        input >> symbol;
        input >> name;
        elements.emplace(atomicNumber, symbol, name);
    }
}