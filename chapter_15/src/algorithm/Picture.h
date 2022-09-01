#pragma once
#include <string>
#include <vector>

#include "Pic_base.h"
#include "Ptr.h"

class Picture
{
	friend Picture frame(const Picture&);
	friend Picture frame_new(const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);
	friend std::ostream& operator<<(std::ostream&, const Picture&);
public:
	// ReSharper disable once CppNonExplicitConvertingConstructor
	Picture(const std::vector<std::string>& = std::vector<std::string>());

private:
	// ReSharper disable once CppNonExplicitConvertingConstructor
	Picture(Pic_base* ptr);
	Ptr<Pic_base> p;
};

Picture frame(const Picture&);
Picture frame_new(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);
