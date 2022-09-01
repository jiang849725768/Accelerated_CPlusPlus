#include "VCat_Pic.h"

VCat_Pic::VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b): top(t), bottom(b)
{
}

Pic_base::wd_sz VCat_Pic::width() const
{
	return std::max(top->width(), bottom->width());
}

Pic_base::ht_sz VCat_Pic::height() const
{
	return top->height() + bottom->height();
}

void VCat_Pic::display(std::ostream& os, const ht_sz row, const bool do_pad) const
{
	wd_sz row_width = 0;
	if (row < top->height())
	{
		top->display(os, row, do_pad);
		row_width = top->width();
	}
	else if (row < height())
	{
		bottom->display(os, row - top->height(), do_pad);
		row_width = bottom->width();
	}

	if (do_pad)
		pad(os, row_width, width());
}
