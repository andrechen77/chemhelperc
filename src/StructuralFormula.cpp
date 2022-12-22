#include "StructuralFormula.h"
#include "MolecularFormula.h"

StructuralFormula::StructuralFormula() :
	composition() {
}

StructuralFormula::StructuralFormula(const std::vector<std::tuple<std::reference_wrapper<Formula>, int>> &&composition) :
	composition(std::move(composition)) {
}

StructuralFormula::StructuralFormula(const std::string formula) :
	composition() {
	
}

MolecularFormula StructuralFormula::toMolecularFormula() const {
	MolecularFormula result;
	for (const auto &[formula, factor] : this->composition) {
		result += formula.get().toMolecularFormula() * factor;
	}
	return result;
}