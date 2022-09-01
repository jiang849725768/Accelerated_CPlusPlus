#include "Ptr.h"

template <>
Vec<char>* clone<Vec<char>>(const Vec<char>* tp)
{
	return new Vec<char>(*tp);
}

bool compare_Core_Ptrs(const Ptr<Core>& a, const Ptr<Core>& b)
{
	return a->name() < b->name();
}
