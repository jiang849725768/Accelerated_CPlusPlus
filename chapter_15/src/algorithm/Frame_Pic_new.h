#pragma once
#include "Pic_base.h"
#include "Ptr.h"

class Frame_Pic_new : public Pic_base
{
	friend Picture frame_new(const Picture&);

	Ptr<Pic_base> p;

	Frame_Pic_new(const Ptr<Pic_base>& pic);

	wd_sz width() const override;
	ht_sz height() const override;
	void display(std::ostream&, ht_sz, bool) const override;
};
