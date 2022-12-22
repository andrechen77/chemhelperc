#include "MolecularFormula.h"

MolecularFormula::MolecularFormula() :
	composition() {
}

MolecularFormula::MolecularFormula(std::map<Atom, int> &&composition) :
	composition(std::move(composition)) {
}

MolecularFormula MolecularFormula::toMolecularFormula() const {
	return *this;
}

MolecularFormula &MolecularFormula::operator+=(const MolecularFormula &other) {
	for (const auto &[atom, number] : other.composition) {
		this->composition[atom] += number;
	}
	
	return *this;
}

MolecularFormula MolecularFormula::operator+(const MolecularFormula &other) const {
	MolecularFormula result = *this;
	result += other;
	return result;
}

std::ostream &operator<<(std::ostream &o, const MolecularFormula &f) {
	for (const auto &[atom, number] : f.composition) {
		o << atom.element.symbol << number;
	}
	
	return o;
}