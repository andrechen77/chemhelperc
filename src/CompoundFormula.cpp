#include "CompoundFormula.h"

CompoundFormula::CompoundFormula() :
	composition() {
}

CompoundFormula::CompoundFormula(const std::map<Formula, int> &&composition) :
	composition(std::move(composition)) {
}

CompoundFormula::CompoundFormula(const std::string formula) :
	composition() {
	
}
