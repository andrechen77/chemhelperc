#pragma once

#include <istream>
#include <string>
#include <cctype>
#include <optional>

namespace chem_parser {
	std::istream &getSymbol(std::istream &i, std::string &output);
}