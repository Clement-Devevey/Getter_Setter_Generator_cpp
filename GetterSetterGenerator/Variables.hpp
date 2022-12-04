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
    std::string type;
    std::string name;
    std::string Name;
    std::string m_name;

    void fillNames();

    Variables const& fillGetter(bool const& b_override, std::stringstream& oss_getter) const;
    Variables const& fillSetter(bool const& b_override, std::stringstream& oss_setter) const;

    Variables const& fillPureVirtualGetter(std::stringstream& oss_getter) const;
    Variables const& fillPureVirtualSetter(std::stringstream& oss_setter) const;

protected:
    void fillGetterDoxygenComments(std::stringstream& oss_getter) const;
    void fillSetterDoxygenComments(std::stringstream& oss_setter) const;
};

// Helper functions
std::istream& operator>>(std::istream& in, Variables& o_var);

std::ostream& operator<<(std::ostream& os, Variables const& i_var);
