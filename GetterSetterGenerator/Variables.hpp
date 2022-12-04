#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

struct Colors
{
    std::string  red{"\033[0;31m"};
    std::string  green{"\033[0;32m"};
    std::string  reset{"\033[0m"};
};

class Variables
{
private:
    Colors colors;
    std::string  colorsOfComments = colors.green;

public:
    std::string  type;
    std::string  name;
    std::string  Name;
    std::string  m_name;

    void fillNames();

    Variables const& printGetter(bool const& b_override, std::stringstream  & os) const;

    Variables const& printSetter(bool const& b_override, std::stringstream  & os) const;

    Variables const& printPureVirtualSetter(std::stringstream  & os) const;
    Variables const& printPureVirtualGetter(std::stringstream  & os) const;

protected:
    void printGetterDoxygenComments(std::stringstream  & os) const;
    void printSetterDoxygenComments(std::stringstream  & os) const;
};

// Helper functions
std::istream& operator>>(std::istream& in, Variables& v);

std::ostream& operator<<(std::ostream& os, Variables const& v);
