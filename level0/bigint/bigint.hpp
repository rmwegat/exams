#pragma once 

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>


class bigint
{
private:
    std::string str;
public:
    bigint();
    bigint(unsigned int num);
    bigint(const bigint &copy);
    ~bigint();

    bigint &operator=(const bigint &source);

    std::string getStr()const;

    bigint operator+(const bigint &other) const;
    bigint &operator+=(const bigint &other);
    
    bigint operator<<(unsigned int num)const;
    bigint operator>>(unsigned int num) const;
    bigint &operator<<=(unsigned int num);
    bigint &operator>>=(unsigned int num);

    bigint operator>>(const bigint &other) const;
    bigint operator<<(const bigint &other) const;
    bigint &operator<<=(const bigint &other);
    bigint &operator>>=(const bigint &other);

    bigint &operator++();
    bigint operator++(int);

    bool operator<(const bigint &other) const;
    bool operator>(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator>=(const bigint &other) const;
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;

};

std::ostream &operator<<(std::ostream &os, const bigint &num);