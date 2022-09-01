#include "Ptr_new.h"

bool compareCorePtrs(const Ptr_new<Core>& a, const Ptr_new<Core>& b)
{
	return a->name() < b->name();
}
