#include "Pic_base.h"

#include <iostream>

Pic_base::~Pic_base() = default;

void Pic_base::pad(std::ostream& os, wd_sz beg, wd_sz end)
{
	while (beg != end)
	{
		os << " ";
		++beg;
	}
}
