#pragma once
#include <string>
#include <vector>

class Picture;

class Pic_base
{
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend class String_Pic;
	friend class Frame_Pic;
	friend class Frame_Pic_new;
	friend class HCat_Pic;
	friend class VCat_Pic;

	using ht_sz = std::vector<std::string>::size_type;
	using wd_sz = std::string::size_type;

	virtual wd_sz width() const =0;
	virtual ht_sz height() const =0;
	virtual void display(std::ostream&, ht_sz, bool) const =0;
protected:
	static void pad(std::ostream&, wd_sz, wd_sz);
public:
	virtual ~Pic_base();
};
