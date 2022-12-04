#include "Variables.hpp"

void Variables::fillNames()
{
    if (m_name.length() < 2) throw std::runtime_error("Var name can't be < 2");
    name = (m_name[0] == 'm' && m_name[1] == '_' ) ? m_name.substr (2, m_name.length()) : m_name;
    Name = name;
    Name[0] = toupper(Name[0]);
}

Variables const& Variables::fillGetter(bool const& b_override, std::stringstream& oss_getter) const
{
    fillSetterDoxygenComments(oss_getter);

    /* Getter code */
    oss_getter << type << " get" << Name << "() const" << (b_override ? " override" : "") << '\n';
    oss_getter << "{" << '\n';
    oss_getter << "\t return " << m_name << ";" << '\n';
    oss_getter << "}" << '\n';
    oss_getter << '\n';

    return *this;
}

Variables const& Variables::fillSetter(bool const& b_override, std::stringstream& oss_setter) const
{
    fillGetterDoxygenComments(oss_setter);

    /* Setter code */
    oss_setter << "void set" << Name << "(" << type << " const& " << name << ")" << (b_override ? " override" : "") << '\n';
    oss_setter << "{" << '\n';
    oss_setter << "\t" << m_name << " = " << name << ";" << '\n';
    oss_setter << "}" << '\n';
    oss_setter << '\n';

    return *this;
}

Variables const& Variables::fillPureVirtualSetter(std::stringstream& oss_setter) const
{
    fillSetterDoxygenComments(oss_setter);

    /* Setter code */
    oss_setter << "virtual void set" << Name << "(" << type << " const& " << name << ") = 0;" << '\n';
    oss_setter << '\n';

    return *this;
}

Variables const& Variables::fillPureVirtualGetter(std::stringstream& oss_getter) const
{
    fillGetterDoxygenComments(oss_getter);

    /* Getter code */
    oss_getter << "virtual " << type << " get" << Name << "() const" << " = 0;" << '\n';
    oss_getter << '\n';

    return *this;
}

void Variables::fillGetterDoxygenComments(std::stringstream& oss_getter) const
{
    oss_getter << colorsOfComments << "/*" << '\n';
    oss_getter << "* @return " << name << '\n';
    oss_getter << "*/" << colors.reset << '\n';
}

void Variables::fillSetterDoxygenComments(std::stringstream  & oss_setter) const
{
    oss_setter << colorsOfComments << "/*" << '\n';
    oss_setter << "* Définit " << name << '\n';
    oss_setter << "* @param " << name << '\n';
    oss_setter << "*/" << colors.reset << '\n';
}

// Helper functions
std::istream& operator>>(std::istream& is, Variables& o_var)
{
    std::string s;
    is >> s;
    const size_t sep = s.find(':');
    if (sep==std::string::npos)
    {
        throw std::runtime_error("bad input");
    } 
    o_var.type  = s.substr(0,sep);
    o_var.m_name = s.substr(sep+1);
    o_var.fillNames();
    return is;
}

std::ostream& operator<<(std::ostream& os, Variables const& i_var)
{
    os << std::setw(15) << std::left << i_var.type << std::setw(15) << i_var.m_name << std::setw(15) << i_var.name << std::setw(15) << i_var.Name << '\n';
    return os;
}
