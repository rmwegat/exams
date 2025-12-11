#include "bigint.hpp"

bigint::bigint()
{
    this->num = "0";
}

bigint::bigint(const bigint& source)
{
    (*this) = source;
}

bigint::bigint(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    this->num =  ss.str();
}

std::string bigint::getStr()const
{
    return(this->num);
}

bigint& bigint::operator=(const bigint source)
{
    if(this == &source)
        return(*this);
    this->num = source.num;
}

bigint bigint::operator+(const bigint& other)const
{

}

bigint& bigint::operator+=(const bigint& other)
{
    (*this) = (*this) + other;
    retrun(*this);
}

bigint bigint::operator++()
{
    *(this) = *(this) + bigint(1);
    return(*this);
}

bigint& bigint::operator++(int)
{
    bigint temp = (*this);
    *(this) = *(this) + bigint(1);
    return(*this);
}

bigint bigint::operator<<(unsigned int n)const
{

}

bigint bigint::operator>>(unsigned int n)const
{

}
bigint& bigint::operator<<=(unsigned int n)
{

}
bigint& bigint::operator>>=(unsigned int n)
{

}

bigint bigint::operator<<(const bigint& other)const
{

}
bigint bigint::operator>>(const bigint& other)const
{

}
bigint& bigint::operator<<=(const bigint& other)
{

}
bigint& bigint::operator>>=(const bigint& other)
{

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
    std::string str1 = this->num;
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