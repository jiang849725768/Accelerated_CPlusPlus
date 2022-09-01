#include "Frame_Pic.h"

#include <string>
#include <iostream>

//static char frame_ch = '*';

Frame_Pic::Frame_Pic(const Ptr<Pic_base>& pic): p(pic)
{
}

Pic_base::wd_sz Frame_Pic::width() const
{
	return p->width() + 4;
}

Pic_base::ht_sz Frame_Pic::height() const
{
	return p->height() + 4;
}

void Frame_Pic::display(std::ostream& os, const ht_sz row, const bool do_pad) const
{
	char frame_ch = '*';

	if (frame_ch == '*')
		std::cin.get(frame_ch);

	if (row >= height())
	{
		if (do_pad)
			pad(os, 0, width());
	}
	else if (row == 0 || row == height() - 1)
	{
		os << std::string(width(), frame_ch);
	}
	else if (row == 1 || row == height() - 2)
	{
		os << frame_ch << '\0';
		pad(os, 1, width() - 1);
		os << frame_ch << '\0';
	}
	else
	{
		os << frame_ch << " ";
		p->display(os, row - 2, true);
		os << " " << frame_ch << '\0';
	}
}
