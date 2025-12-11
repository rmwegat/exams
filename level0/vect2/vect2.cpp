#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(const vect2& copy) : x(copy.x), y(copy.y) {}

vect2::vect2(int xx, int yy) : x(xx), y(yy) {}

vect2::~vect2() {}

vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return x;
	return y;
}
int vect2::operator[](int index)const
{
	if (index == 0)
		return x;
	return y;
}

vect2 vect2::operator-()const
{
	return vect2(-x, -y);
}
vect2 vect2::operator*(int num)const
{
	return vect2(x * num, y * num);
}

vect2& vect2::operator*=(int num)
{
	x *= num;
	y *= num;
	return *this;
}

vect2& vect2::operator*=(const vect2& other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}
vect2& vect2::operator+=(const vect2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
vect2& vect2::operator-=(const vect2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

vect2 vect2::operator*(const vect2& other)const
{
	return vect2(x * other.x, y * other.y);
}
vect2 vect2::operator+(const vect2& other)const
{
	return vect2(x + other.x, y + other.y);
}
vect2 vect2::operator-(const vect2& other)const
{
	return vect2(x - other.x, y - other.y);
}

vect2& vect2::operator++()
{
	x++; y++;
	return *this;
}
vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	++(*this);
	return temp;
}
vect2& vect2::operator--()
{
	x--; y--;
	return *this;
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	--(*this);
	return temp;
}

bool vect2::operator==(const vect2& other)
{
	return(x == other.x && y == other.y);
}
bool vect2::operator!=(const vect2& other)
{
	return(x != other.x || y != other.y);
}

vect2 operator*(int num, const vect2& other)
{
	return vect2(other * num);
}

std::ostream& operator<<(std::ostream& os, const vect2& other)
{
	std::cout << "{" << other[0] << ", " << other[1] << "}";
	return os;
}