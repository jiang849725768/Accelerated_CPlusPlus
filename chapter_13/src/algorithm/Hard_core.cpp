#include "Hard_core.h"

Hard_core::Hard_core(std::istream& is): Core(is)
{
}

double Hard_core::grade() const
{
	if (!valid())
		return (midterm + final) / 2.0;
	return Core::grade();
}
