#pragma once
#include "Pic_base.h"

class String_Pic : public Pic_base
{
	friend class Picture;
	std::vector<std::string> data;
	String_Pic(const std::vector<std::string>& v);

	wd_sz width() const override;
	ht_sz height() const override;
	void display(std::ostream&, ht_sz, bool) const override;
};
