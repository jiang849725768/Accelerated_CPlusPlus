#pragma once
#include "Pic_base.h"
#include "Ptr.h"

class HCat_Pic : public Pic_base
{
	friend Picture hcat(const Picture&, const Picture&);

	Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r);

	wd_sz width() const override;
	ht_sz height() const override;
	void display(std::ostream&, ht_sz, bool) const override;
	void display_old(std::ostream&, ht_sz, bool) const;
};
