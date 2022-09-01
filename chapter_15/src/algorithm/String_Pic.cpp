#include "String_Pic.h"
#include <iostream>

String_Pic::String_Pic(const std::vector<std::string>& v): data(v)
{
}

Pic_base::wd_sz String_Pic::width() const
{
	wd_sz maxlen = 0;
	for (const auto& row : data)
		maxlen = std::max(maxlen, row.size());
	return maxlen;
}

Pic_base::ht_sz String_Pic::height() const
{
	return data.size();
}

void String_Pic::display(std::ostream& os, const ht_sz row, const bool do_pad) const
{
	wd_sz start = 0;
	if (row < height())
	{
		os << data[row];
		start = data[row].size();
	}
	if (do_pad)
		pad(os, start, width());
}
