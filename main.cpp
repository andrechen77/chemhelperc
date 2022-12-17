#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <optional>
#include <map>

struct Element {
	int atomicNumber;
	std::string symbol;
	std::string name;

	Element(int atomicNumber, const std::string &symbol, const std::string &name) :
		atomicNumber(atomicNumber), symbol(symbol), name(name) {
	}

	Atom getAtom() {
		return Atom(*this);
	}

    friend bool operator<(const Element &a, const Element &b) {
        return a.atomicNumber < b.atomicNumber;
    }

	friend std::ostream &operator<<(std::ostream &o, const Element &e) {
		o << e.atomicNumber << "\t" << e.symbol << "\t" << e.name;
		return o;
	}
};

class PeriodicTable {
	public:

	std::set<Element> elements;
	
	PeriodicTable(std::istream &input) :
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

	std::optional<Atom> getAtom(const std::string &symbol) {
		for (const Element &e : elements) {
			if (e.symbol == symbol) {
				return {e};
			}
		}
		return {};
	}
};

struct Atom {
	const Element &element;

	Atom(const Element &element) :
		element(element) {
		
	}

	const Element &operator*() const {
		return element;
	}
};

struct Formula {
	std::map<Atom, int> composition;
	
	Formula() :
		composition() {
	}

	Formula(const std::map<Atom, int> &&composition) :
		composition(std::move(composition)) {
	}

	Formula(const std::string formula) :
		composition() {
		
	}

	Formula &addAtom(const Atom &atom, int number) {
		composition[atom] += number;
		if (composition[atom] == 0) {
			composition.erase(atom);
		}
		return *this;
	}
};

int main() {
	std::cout << "Hello World!\n\n";

	std::ifstream pTableFile("pTable.txt");
    PeriodicTable pTable(pTableFile);

	for (const Element &e : pTable.elements) {
		std::cout << e << "\n";
	}

	std::string userInput;
	while (true) {
		std::cout << "Enter element symbol: ";
		std::cin >> userInput;
		if (userInput == "stop") {
			break;
		}

		std::optional<Atom> e = pTable.getAtom(userInput);
		if (e.has_value()) {
			const Atom &el = *e;
			std::cout << "Found element " << (*el) << "\n";
		} else {
			std::cout << "Found no matching element\n";
		}
	}
}