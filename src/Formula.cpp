#include "Formula.h"

Formula::Formula() :
    composition() {
}

Formula::Formula(const std::map<Atom, int> &&composition) :
    composition(std::move(composition)) {
}

Formula::Formula(const std::string formula) :
    composition() {
    
}
