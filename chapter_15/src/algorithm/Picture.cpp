#include "Picture.h"

#include <iostream>

#include "Frame_Pic.h"
#include "Frame_Pic_new.h"
#include "HCat_Pic.h"
#include "String_Pic.h"
#include "VCat_Pic.h"


Picture::Picture(const std::vector<std::string>& v): p(new String_Pic(v))
{
}

Picture::Picture(Pic_base* ptr): p(ptr)
{
}

Picture frame(const Picture& pic)
{
	return new Frame_Pic(pic.p);
}

Picture frame_new(const Picture& pic)
{
	return new Frame_Pic_new(pic.p);
}

Picture hcat(const Picture& l, const Picture& r)
{
	return new HCat_Pic(l.p, r.p);
}

Picture vcat(const Picture& t, const Picture& b)
{
	return new VCat_Pic(t.p, b.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture)
{
	const Pic_base::ht_sz ht = picture.p->height();
	for (Pic_base::ht_sz i = 0; i < ht; ++i)
	{
		picture.p->display(os, i, false);
		os << std::endl;
	}

	return os;
}
