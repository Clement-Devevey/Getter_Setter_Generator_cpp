#include "Variables.hpp"

void Variables::fillNames()
{
    name = (m_name[0] == 'm' && m_name[1] == '_' ) ? m_name.substr (2, m_name.length()) : m_name;
    Name = name;
    Name[0] = toupper(Name[0]);
}

Variables const& Variables::printGetter() const
{
    /* Getter Doxygen comments */
    std::cout << colorsOfComments << "/*" << std::endl;
    std::cout << "* @return " << name << std::endl;
    std::cout << "*/" << colors.reset << std::endl;

    /* Getter code */
    std::cout << type << " get" << Name << "() const" << std::endl;
    std::cout << "{" << std::endl;
    std::cout << "\t return " << m_name << ";" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << std::endl;

    return *this;
}

Variables const& Variables::printSetter() const
{
    /* Setter Doxygen comments */
    std::cout << colorsOfComments << "/*" << std::endl;
    std::cout << "* Définit " << name << std::endl;
    std::cout << "* @param " << name << std::endl;
    std::cout << "*/" << colors.reset << std::endl;

    /* Setter code */
    std::cout << "void set" << Name << "(" << type << " const& " << name << ")" << std::endl;
    std::cout << "{" << std::endl;
    std::cout << "\t" << m_name << " = " << name << ";" << std::endl;
    std::cout << "}" << std::endl;
    std::cout << std::endl;

    return *this;
}


// Helper functions
std::istream& operator>>(std::istream& in, Variables& v)
{
    std::string s;
    in >> s;
    const size_t sep = s.find(':');
    if (sep==std::string::npos) 
    {
        throw std::runtime_error("bad input");
    } 
    v.type  = s.substr(0,sep);
    v.m_name = s.substr(sep+1);
    v.fillNames();
    return in;
}

std::ostream& operator<<(std::ostream& os, Variables const& v)
{
    std::cout << std::setw(15) << std::left << v.type << std::setw(15) << v.m_name << std::setw(15) << v.name << std::setw(15) << v.Name << '\n';
    return os;
}