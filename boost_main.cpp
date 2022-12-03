// Boost
#include <boost/compressed_pair.hpp>
#include <boost/program_options.hpp>

// STL
#include <iomanip>  // std::setw
#include <iostream>
#include <vector>

// Local
#include "Variables.hpp"

using namespace boost::program_options;
using argsType = std::vector<Variables>;

/*
* Callback when the option Variable is filled with arguments.
*/
void on_variables(argsType const& args)
{
    std::cout << "VARIABLES DETECTED: " << '\n';
  
    for (auto const& arg: args)
    {
        //std::cout << arg;
        arg.printSetter().printGetter();
    } 
}

int main(int argc, const char *argv[])
{
    try
    {
        options_description desc{"Options"};
        desc.add_options()
            ("help,h", "Help screen.")
            ("variables,v", value<argsType>()->multitoken()->zero_tokens()->composing()->notifier(on_variables), 
                    "Variables with their types to which setter/getter will be generate. Exemple: ./boost_main.exe -v MyClasse1:m_var1 MyClasse2:m_var2.")
            ("override", "Generate overrided getter/setter.")
            ("pure-virtual", "Generate virtual pure getter/setter.");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << '\n';
        }

    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}