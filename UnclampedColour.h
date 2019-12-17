#pragma once
#include "Colour.h"

//
// Colour structure that does not clamp any of its values.
//
class UnclampedColour
{
public:
	UnclampedColour();
	UnclampedColour(const float& red, const float& green, const float& blue);
	UnclampedColour(const UnclampedColour& copy);
	UnclampedColour(const Colour& copy);

	const float& GetRed() const;
	const float& GetGreen() const;
	const float& GetBlue() const;

	void SetRed(const float& red);
	void SetGreen(const float& green);
	void SetBlue(const float& blue);

	void Normalise();
	
	UnclampedColour operator+(const UnclampedColour& rhs);
	UnclampedColour operator-(const UnclampedColour& rhs);
	UnclampedColour operator*(const UnclampedColour& rhs);
	UnclampedColour operator/(const UnclampedColour& rhs);

	const UnclampedColour& operator+=(const UnclampedColour& rhs);
	const UnclampedColour& operator-=(const UnclampedColour& rhs);
	const UnclampedColour& operator*=(const UnclampedColour& rhs);
	const UnclampedColour& operator/=(const UnclampedColour& rhs);

	UnclampedColour operator+(const float& rhs);
	UnclampedColour operator-(const float& rhs);
	UnclampedColour operator*(const float& rhs);
	UnclampedColour operator/(const float& rhs);

	const UnclampedColour& operator+=(const float& rhs);
	const UnclampedColour& operator-=(const float& rhs);
	const UnclampedColour& operator*=(const float& rhs);
	const UnclampedColour& operator/=(const float& rhs);

	const UnclampedColour& operator=(const UnclampedColour& rhs);
	const UnclampedColour& operator=(const Colour& rhs);
	const UnclampedColour& operator=(const float& rhs);

private:
	float _red;
	float _green;
	float _blue;
};
