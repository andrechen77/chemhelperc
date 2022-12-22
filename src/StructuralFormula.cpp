#include "StructuralFormula.h"
#include "MolecularFormula.h"
#include "chem_parser.h"

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
	for (const auto &[formula, factor] : this->composition) {
		result += formula.get().toMolecularFormula() * factor;
	}
	return result;
}

void StructuralFormula::printTo(std::ostream &o) const {
	o << "(";
	for (const auto &[formula, factor] : composition) {
		formula.get().printTo(o);
		o << factor;
	}
	o << ")";
}