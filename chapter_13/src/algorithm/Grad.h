#pragma once

#include "Core.h"

class Grad : public Core
{
	friend class Student_info;
public:
	Grad();
	~Grad() override;

	explicit Grad(std::istream& is);

	double grade() const override;
	std::istream& read(std::istream&) override;
	bool great() const override;
protected:
	Grad* clone() const override;
private:
	double thesis{};
};
