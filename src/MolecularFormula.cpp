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

MolecularFormula &MolecularFormula::operator*=(int factor) {
	for (auto &[atom, number] : this->composition) {
		number *= factor;
	}

	return *this;
}

MolecularFormula MolecularFormula::operator*(int factor) const {
	MolecularFormula result = *this;
	result *= factor;
	return result;
}

void MolecularFormula::printTo(std::ostream &o, bool inside) const {
	for (const auto &[atom, number] : composition) {
		o << atom.getElement().symbol;
		if (number > 1) {
			o << number;
		}
	}
}