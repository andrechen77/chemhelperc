#include "Formula.h"

std::ostream &operator<<(std::ostream &o, const Formula &f) {
	f.printTo(o);
	return o;
}