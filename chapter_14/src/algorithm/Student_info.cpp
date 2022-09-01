#include "Student_info.h"

#include "Grad.h"

Student_info::Student_info(): cp(nullptr)
{
}

Student_info::Student_info(std::istream& is): cp(nullptr)
{
	read(is);
}

std::istream& Student_info::read(std::istream& is)
{
	if (char ch; is >> ch)
	{
		switch (ch)
		{
		case 'U':
			cp = new Core(is);
			break;
		case 'G':
			cp = new Grad(is);
			break;
		default:
			std::cout << "Problem is here" << std::endl;
			throw std::runtime_error("Wrong student type");
		}
	}
	else
		cp = nullptr;

	return is;
}

std::string Student_info::name() const
{
	if (cp)
		return cp->name();
	throw std::runtime_error("uninitialized Student");
}

double Student_info::grade() const
{
	if (cp)
		return cp->grade();
	throw std::runtime_error("uninitialized Student");
}

bool Student_info::valid() const
{
	return cp->valid();
}

bool Student_info::great() const
{
	return cp->great();
}

bool Student_info::pass() const
{
	return cp->grade() >= 60.0;
}


std::string Student_info::letter_grade() const
{
	return cp->letter_grade();
}

bool Student_info::compare(const Student_info& s1, const Student_info& s2)
{
	return s1.name() < s2.name();
}
