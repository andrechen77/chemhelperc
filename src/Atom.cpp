#include "Atom.h"
#include "Element.h"

Atom::Atom(const Element &element) :
    element(element) {
}

const Element &Atom::operator*() const {
    return element;
}