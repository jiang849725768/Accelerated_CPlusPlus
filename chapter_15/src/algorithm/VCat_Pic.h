#pragma once
#include "Pic_base.h"
#include "Ptr.h"

class VCat_Pic : public Pic_base
{
	friend Picture vcat(const Picture&, const Picture&);

	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b);

	wd_sz width() const override;
	ht_sz height() const override;
	void display(std::ostream&, ht_sz, bool) const override;
};
