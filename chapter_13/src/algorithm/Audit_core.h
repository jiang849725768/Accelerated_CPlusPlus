#pragma once
#include "Core.h"

class Audit_core : public Core
{
public:
	explicit Audit_core(std::istream& is);

	double grade() const override;
	std::istream& read(std::istream&) override;
};
