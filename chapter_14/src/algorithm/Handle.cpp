#include "Handle.h"

bool compare_Core_handles(const Handle<Core>& a, const Handle<Core>& b)
{
	return a->name() < b->name();
}
