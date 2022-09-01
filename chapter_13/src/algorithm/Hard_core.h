#pragma once

#include "Core.h"

class Hard_core : public Core
{
public:
	explicit Hard_core(std::istream& is);

	double grade() const override;
};
