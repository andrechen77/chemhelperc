#include "StructuralFormula.h"

StructuralFormula::StructuralFormula() :
	composition() {
}

StructuralFormula::StructuralFormula(const std::vector<std::tuple<Formula, int>> &&composition) :
	composition(std::move(composition)) {
}

StructuralFormula::StructuralFormula(const std::string formula) :
	composition() {
	
}
