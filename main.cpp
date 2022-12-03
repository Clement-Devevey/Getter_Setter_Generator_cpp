#include <iostream>
#include <string.h>

namespace colors
{
    const std::string red("\033[0;31m");
    const std::string green("\033[0;32m");
    const std::string reset("\033[0m");
}

void error(std::string const& s1, std::string const& s2, std::string const& s3)
{
    throw std::runtime_error(s1 + s2 + s3);
}

void error(std::string const& s1, std::string const& s2)
{
    throw std::runtime_error(s1 + s2);
}

void error(std::string const& s)
{
    throw std::runtime_error(s);
}


int main(int argc,char* argv[])
{
    const std::string colorsOfComments = colors::green;

    try
    {
        /* first arg is name of command */
        if(argc==1)
        {
            error("This program generates getters and setters. Simply use 'main' and add all your variables after. Example: main int m_var1 Type m_var2");
        }

        if (strcmp(argv[1], "-h") == 0 || argc == 2)
        {
            error("This program generates getters and setters. Simply use 'main' and add all your variables after. Example: main int m_var1 Type m_var2");
        }

        std::cout << std::endl;

        char nameOfVar[50];
        char upperNameOfVar[50];

        /* iterate over args. Working by pair. */
        for(int i = 1; i < argc-1 ; i=i+2)
        {
            /* Check syntax and get variables names: m_var => var => Var */
            if (argv[i+1][0] == 'm' && argv[i+1][1] == '_')
            {
                strncpy(nameOfVar,  argv[i+1] + 2, strlen(argv[i+1]));
                strcpy(upperNameOfVar, nameOfVar);
                upperNameOfVar[0] = toupper(upperNameOfVar[0]);
            }
            else
            {
                error("Wrong variables syntax: ",  argv[i+1], ". m_ is mandatory. Example: m_var1.");
            }

            /* Setter Doxygen comments */
            std::cout << colorsOfComments << "/*" << std::endl;
            std::cout << "* Définit " << nameOfVar << std::endl;
            std::cout << "* @param " << nameOfVar << std::endl;
            std::cout << "*/" << colors::reset << std::endl;

            /* Setter code */
            std::cout << "void set" << upperNameOfVar << "(" << argv[i] << " const& " << nameOfVar << ")" << std::endl;
            std::cout << "{" << std::endl;
            std::cout << "\t" << argv[i+1] << " = " << nameOfVar << ";" << std::endl;
            std::cout << "}" << std::endl;
            std::cout << std::endl;

            /* Getter Doxygen comments */
            std::cout << colorsOfComments << "/*" << std::endl;
            std::cout << "* @return " << argv[i+1] << std::endl;
            std::cout << "*/" << colors::reset << std::endl;

            /* Getter code */
            std::cout << argv[i] << " get" << upperNameOfVar << "() const" << std::endl;
            std::cout << "{" << std::endl;
            std::cout << "\t return " << argv[i+1] << ";" << std::endl;
            std::cout << "}" << std::endl;
            std::cout << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << colors::red << e.what() << colors::reset <<'\n';
        return 1;
    }
        
    return 0;
}
