#include "Frame_Pic_new.h"

#include <string>
#include <iostream>

Frame_Pic_new::Frame_Pic_new(const Ptr<Pic_base>& pic): p(pic)
{
}

Pic_base::wd_sz Frame_Pic_new::width() const
{
	return p->width() + 4;
}

Pic_base::ht_sz Frame_Pic_new::height() const
{
	return p->height() + 4;
}

void Frame_Pic_new::display(std::ostream& os, const ht_sz row, const bool do_pad) const
{
	if (row >= height())
	{
		if (do_pad)
			pad(os, 0, width());
	}
	else if (row == 0)
	{
		os << '1';
		os << std::string(width() - 2, '-');
		os << '2';
	}
	else if (row == height() - 1)
	{
		os << '3';
		os << std::string(width() - 2, '-');
		os << '4';
	}
	else if (row == 1 || row == height() - 2)
	{
		os << "|";
		pad(os, 1, width() - 1);
		os << "|";
	}
	else
	{
		os << "| ";
		p->display(os, row - 2, true);
		os << " |";
	}
}
