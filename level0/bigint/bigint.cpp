#include "bigint.hpp"

bigint::bigint()
{
    this->str = "0";
}

bigint::bigint(const bigint& source)
{
    (*this) = source;
}

bigint::~bigint()
{
    // Nothing to clean up for string
}

bigint::bigint(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    this->str =  ss.str();
}

std::string bigint::getStr()const
{
    return(this->str);
}

bigint& bigint::operator=(const bigint& source)
{
    if(this == &source)
        return(*this);
    this->str = source.str;
    return(*this);
}

bigint bigint::operator+(const bigint& other)const
{
    // Simple implementation: convert to integers, add, and convert back
    // Note: This is a basic implementation for demonstration
    unsigned int this_num = std::atoi(this->str.c_str());
    unsigned int other_num = std::atoi(other.str.c_str());
    return bigint(this_num + other_num);
}

bigint& bigint::operator+=(const bigint& other)
{
    (*this) = (*this) + other;
    return(*this);
}

bigint& bigint::operator++()
{
    *(this) = *(this) + bigint(1);
    return(*this);
}

bigint bigint::operator++(int)
{
    bigint temp = (*this);
    *(this) = *(this) + bigint(1);
    return(temp);
}

bigint bigint::operator<<(unsigned int n)const
{
    bigint result = *this;
    for (unsigned int i = 0; i < n; i++)
        result.str += "0";
    return result;
}

bigint bigint::operator>>(unsigned int n)const
{
    bigint result = *this;
    for (unsigned int i = 0; i < n && !result.str.empty(); i++) {
        result.str.pop_back();
    }
    if (result.str.empty())
        result.str = "0";
    return result;
}
bigint& bigint::operator<<=(unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        this->str += "0";
    return *this;
}
bigint& bigint::operator>>=(unsigned int n)
{
    for (unsigned int i = 0; i < n && !this->str.empty(); i++) {
        this->str.pop_back();
    }
    if (this->str.empty())
        this->str = "0";
    return *this;
}

bigint bigint::operator<<(const bigint& other)const
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) << n;
}
bigint bigint::operator>>(const bigint& other)const
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) >> n;
}
bigint& bigint::operator<<=(const bigint& other)
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) <<= n;
}
bigint& bigint::operator>>=(const bigint& other)
{
    unsigned int n = std::atoi(other.str.c_str());
    return (*this) >>= n;
}

bool bigint::operator==(const bigint& other) const
{
    if (this->getStr() == other.getStr())
        return(true);
    return(false);
}
bool bigint::operator!=(const bigint& other) const
{
    return(!((*this) == (other)));
}
bool bigint::operator<(const bigint& other) const
{
    std::string str1 = this->str;
    std::string str2 = other.getStr();

    if (str1.length() != str2.length())
        return(str1.length() < str2.length());
    return(str1 < str2);
}
bool bigint::operator>(const bigint& other) const
{
    return(!((*this) < other));
}
bool bigint::operator<=(const bigint& other) const
{
    return((((*this) < other) || ((*this) == other)));
}
bool bigint::operator>=(const bigint& other) const
{
    return((((*this) > other) || ((*this) == other)));
}

std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
    output << obj.getStr();
    return(output);
}