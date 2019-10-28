#include "Vertex.h"

Vertex::Vertex() : Vertex(0, 0, 0, 1)
{ }

Vertex::Vertex(float x, float y, float z) : Vertex(x, y, z, 1)
{ }

Vertex::Vertex(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w)
{ }

Vertex::Vertex(const Vertex& other) : Vertex(other._x, other._y, other._z, other._w)
{ }

const float& Vertex::GetX() const
{
	return _x;
}

const float& Vertex::GetY() const
{
	return _y;
}

const float& Vertex::GetZ() const
{
	return _z;
}

const float& Vertex::GetW() const
{
	return _w;
}

void Vertex::SetX(const float& x)
{
	_x = x;
}

void Vertex::SetY(const float& y)
{
	_y = y;
}

void Vertex::SetZ(const float& z)
{
	_z = z;
}

void Vertex::SetW(const float& w)
{
	_w = w;
}

const Vertex& Vertex::operator=(const Vertex& rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	_z = rhs._z;
	_w = rhs._w;

	return *this;
}

const Vertex Vertex::operator+(const Vertex& rhs) const
{
	Vertex sum;
	sum._x = _x + rhs._x;
	sum._y = _y + rhs._y;
	sum._z = _z + rhs._z;
	sum._w = _w + rhs._w;

	return sum;
}

const Point<float> Vertex::AsPoint()
{
	return { _x, _y };
}
