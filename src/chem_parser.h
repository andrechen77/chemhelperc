#pragma once

#include <istream>
#include <string>
#include <cctype>
#include <optional>

namespace chem_parser {
    std::optional<std::string> getSymbol(std::istream &i) {
        if (i.eof()) {
            return {};
        }

        std::string symbol;
        
        char nextCharacter;
        do {
            nextCharacter = i.get();
            symbol.push_back(nextCharacter);
            nextCharacter = i.peek();
        } while (std::islower(nextCharacter));

        return {symbol};
    }
}