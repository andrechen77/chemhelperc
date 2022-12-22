#include "StructuralFormula.h"
#include "MolecularFormula.h"

StructuralFormula::StructuralFormula() :
	composition() {
}

StructuralFormula::StructuralFormula(const std::vector<std::tuple<std::reference_wrapper<Formula>, int>> &&composition) :
	composition(std::move(composition)) {
}

StructuralFormula::StructuralFormula(const PeriodicTable &pTable, const std::string &formula) :
	composition() {
	// TODO
}

MolecularFormula StructuralFormula::toMolecularFormula() const {
	MolecularFormula result;
	for (const auto &[formula, number] : this->composition) {
		result += formula.get().toMolecularFormula() * number;
	}
	return result;
}

void StructuralFormula::printTo(std::ostream &o, bool inside) const {
	if (inside) {
		o << "(";
	}
	for (const auto &[formula, number] : composition) {
		formula.get().printTo(o, true);
		if (number > 1) {
			o << number;
		}
	}
	if (inside) {
		o << ")";
	}
}