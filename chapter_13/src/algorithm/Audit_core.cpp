#include "Audit_core.h"

Audit_core::Audit_core(std::istream& is)
{
	Audit_core::read(is);
}

double Audit_core::grade() const
{
	return NULL;
}

std::istream& Audit_core::read(std::istream& in)
{
	in >> n;

	return in;
}
