#pragma once

#include <istream>
#include <string>
#include <cctype>
#include <optional>

namespace chem_parser {
    std::istream &getSymbol(std::istream &i, std::string &output) {
        output.clear();
        
        if (i.eof()) {
            i.setstate(std::ios_base::failbit);
            return i;
        }
        
        output.push_back(i.get());
        while (!i.eof() && std::islower(i.peek())) {
            output.push_back(i.get());
        }
        
        return i;
    }
}