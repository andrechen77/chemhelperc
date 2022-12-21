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
	return MolecularFormula{}; // TODO
}