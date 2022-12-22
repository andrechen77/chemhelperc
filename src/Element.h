#pragma once

#include <string>
#include <iostream>

struct Element {
	int atomicNumber;
	std::string symbol;
	std::string name;

	Element(int atomicNumber, const std::string &symbol, const std::string &name);

	bool operator<(const Element &other) const;

	bool operator==(const Element &other) const;

	friend std::ostream &operator<<(std::ostream &o, const Element &e);
};