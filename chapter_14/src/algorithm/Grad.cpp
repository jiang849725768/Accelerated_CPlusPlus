#include "Grad.h"

#include <algorithm>

Grad::Grad(): thesis(0)
{
	std::cerr << "Grad constructor once" << std::endl;
}

Grad::~Grad()
{
	std::cerr << "Grad destructor once" << std::endl;
}

Grad::Grad(std::istream& is)
{
	std::cerr << "Grad read constructor once" << std::endl;
	Grad::read(is);
}

Grad* Grad::clone() const
{
	return new Grad(*this);
}

double Grad::grade() const
{
	//std::cout << "Grad::grade" << std::endl;
	return std::min(Core::grade(), thesis);
}

std::istream& Grad::read(std::istream& in)
{
	read_common(in);
	in >> thesis;
	read_hw(in);
	return in;
}

bool Grad::great() const
{
	return Core::great() && thesis != 0.0;
}
