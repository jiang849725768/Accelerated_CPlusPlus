#include "HCat_Pic.h"

HCat_Pic::HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r): left(l), right(r)
{
}

Pic_base::wd_sz HCat_Pic::width() const
{
	return left->width() + right->width();
}

Pic_base::ht_sz HCat_Pic::height() const
{
	return std::max(left->height(), right->height());
}

void HCat_Pic::display(std::ostream& os, ht_sz row, bool do_pad) const
{
	ht_sz diff = 0;
	if (left->height() > right->height())
	{
		diff = (left->height() - right->height()) / 2;
		if (row < diff || row >= height() - diff)
		{
			left->display(os, row, do_pad);
		}
		else
		{
			left->display(os, row, do_pad);
			right->display(os, row - diff, do_pad);
		}
	}
	else
	{
		diff = (right->height() - left->height()) / 2;
		if (row < diff || row >= height() - diff)
		{
			pad(os, 0, left->width());
			right->display(os, row, do_pad);
		}
		else
		{
			left->display(os, row - diff, do_pad);
			right->display(os, row, do_pad);
		}
	}
}

void HCat_Pic::display_old(std::ostream& os, const ht_sz row, const bool do_pad) const
{
	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}
