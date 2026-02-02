#include "bigint.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(const bigint &copy) : str(copy.str) {}

bigint::bigint(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    this->str = ss.str();
}

bigint::~bigint() {}

bigint &bigint::operator=(const bigint &source)
{
    if (this != &source)
    {
        this->str = source.str;
    }
    return (*this);
}

std::string bigint::getStr()const
{
    return(this->str);
}

// ============ BASE OPERATORS ============

bigint bigint::operator+(const bigint &other)const
{
    unsigned int a = std::atoi(this->str.c_str());
    unsigned int b = std::atoi(other.str.c_str());
    return (a + b);
}

bigint bigint::operator<<(unsigned int n) const
{
    bigint result = *this;
    for (unsigned int i = 0; i < n; i++)
        result.str += "0";
    return result;
}

bigint bigint::operator>>(unsigned int n)const
{
    bigint result = *this;
    for (unsigned int i = 0; i < n && !result.str.empty(); i++)
    {
        result.str.pop_back();
    }
    if (result.str.empty())
        result.str = "0";
    return result;
}

bool bigint::operator==(const bigint &other) const
{
    return this->str == other.str;
}

bool bigint::operator<(const bigint &other) const
{
    if (this->str.length() != other.str.length())
    return this->str.length() < other.str.length();
    return this->str < other.str;
}

// ============ DEPENDENT OPERATORS ============

bigint &bigint::operator>>=(unsigned int n)
{
    for (unsigned int i = 0; i < n && !this->str.empty(); i++)
        this->str.pop_back();
    if (this->str.empty())
        this->str = "0";
    return (*this);
}

bool bigint::operator>(const bigint &other) const
{
    return other < (*this);
}

bool bigint::operator<=(const bigint &other) const
{
    return !(other < (*this));
}

bool bigint::operator>=(const bigint &other) const
{
    return !(*this < other);
}

bool bigint::operator!=(const bigint &other) const
{
    return !(*this == other);
}

bigint &bigint::operator+=(const bigint &other)
{
    (*this) = (*this) + other;
    return (*this);
}

bigint &bigint::operator++()
{
    (*this) = (*this) + bigint(1);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint temp = (*this);
    (*this) = (*this) + bigint(1);
    return temp;
}

bigint &bigint::operator<<=(unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        this->str += "0";
    return (*this);
}

bigint bigint::operator<<(const bigint &other) const
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) << n;
}

bigint bigint::operator>>(const bigint &other) const
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) >> n;
}

bigint &bigint::operator<<=(const bigint &other)
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) <<= n;
}

bigint &bigint::operator>>=(const bigint &other)
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) >>= n;
}

std::ostream &operator<<(std::ostream &os, const bigint &num)
{
    os << num.getStr();
    return(os);
}