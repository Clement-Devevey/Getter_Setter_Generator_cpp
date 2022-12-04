#include "Variables.hpp"

void Variables::fillNames()
{
    if (m_name.length() < 2) throw std::runtime_error("Var name can't be < 2");
    name = (m_name[0] == 'm' && m_name[1] == '_' ) ? m_name.substr (2, m_name.length()) : m_name;
    Name = name;
    Name[0] = toupper(Name[0]);
}

Variables const& Variables::printGetter(bool const& b_override, std::stringstream  & os) const
{
    printSetterDoxygenComments(os);

    /* Getter code */
    os << type << " get" << Name << "() const" << (b_override ? " override" : "") << '\n';
    os << "{" << '\n';
    os << "\t return " << m_name << ";" << '\n';
    os << "}" << '\n';
    os << '\n';

    return *this;
}

Variables const& Variables::printSetter(bool const& b_override, std::stringstream  & os) const
{
    printGetterDoxygenComments(os);

    /* Setter code */
    os << "void set" << Name << "(" << type << " const& " << name << ")" << (b_override ? " override" : "") << '\n';
    os << "{" << '\n';
    os << "\t" << m_name << " = " << name << ";" << '\n';
    os << "}" << '\n';
    os << '\n';

    return *this;
}

Variables const& Variables::printPureVirtualSetter(std::stringstream  & os) const
{
    printSetterDoxygenComments(os);

    /* Setter code */
    os << "virtual void set" << Name << "(" << type << " const& " << name << ") = 0;" << '\n';
    os << '\n';

    return *this;
}

Variables const& Variables::printPureVirtualGetter(std::stringstream  & os) const
{
    printGetterDoxygenComments(os);

    /* Getter code */
    os << "virtual " << type << " get" << Name << "() const" << " = 0;" << '\n';
    os << '\n';

    return *this;
}

void Variables::printGetterDoxygenComments(std::stringstream  & os) const
{
    os << colorsOfComments << "/*" << '\n';
    os << "* @return " << name << '\n';
    os << "*/" << colors.reset << '\n';
}

void Variables::printSetterDoxygenComments(std::stringstream  & os) const
{
    os << colorsOfComments << "/*" << '\n';
    os << "* Définit " << name << '\n';
    os << "* @param " << name << '\n';
    os << "*/" << colors.reset << '\n';
}

// Helper functions
std::istream& operator>>(std::istream& in, Variables& v)
{
    std::string  s;
    in >> s;
    const size_t sep = s.find(':');
    if (sep==std::string ::npos)
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
    os << std::setw(15) << std::left << v.type << std::setw(15) << v.m_name << std::setw(15) << v.name << std::setw(15) << v.Name << '\n';
    return os;
}
