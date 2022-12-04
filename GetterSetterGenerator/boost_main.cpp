// Boost
//#include <boost/chrono.hpp>
#include <boost/program_options.hpp>

// STL
#include <iomanip>  // std::setw
#include <iostream>
#include <vector>
#include <sstream>

// Local
#include "Variables.hpp"

using namespace boost::program_options;
using argsType = std::vector<Variables>;

int main(int argc, const char *argv[])
{
    //boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();

    try
    {
        options_description desc{"Options"};
        desc.add_options()
            ("help,h", "Help screen.")
            ("variables,v", value<argsType>()->multitoken()->zero_tokens()->composing(),
                    "Variables with their types to which setter/getter will be generate. Exemple: ./boost_main.exe -v MyClasse1:m_var1 MyClasse2:m_var2.")
            ("override,o", "Generate overrided getter/setter.")
            ("pure-virtual,p", "Generate virtual pure getter/setter.");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        //notify(vm);

        if (vm.count("help"))
        {
            std::cout << desc << '\n';
            return 0;
        }

        bool b_override{false};
        bool b_pureVirtual{false};

        if (vm.count("override"))
        {
            b_override = true;
        }

        if (vm.count("pure-virtual"))
        {
            b_pureVirtual = true;
        }

        if (vm.count("variables"))
        {
            std::cout << "override set to " << b_override << '\n';
            std::cout << "pure-virtual set to " << b_pureVirtual << '\n';
            //on_variables(vm["variables"].as<argsType>());
            std::cout << "VARIABLES DETECTED: " << '\n';

            std::stringstream virtualGettersSetters{};
            std::stringstream gettersSetters{};

            for (auto const& arg: vm["variables"].as<argsType>())
            {
                //std::cout << arg;
                if (b_pureVirtual)
                {
                    arg.fillPureVirtualGetter(virtualGettersSetters).fillPureVirtualSetter(virtualGettersSetters);
                    if (b_override) arg.fillGetter(b_override, gettersSetters).fillSetter(b_override, gettersSetters);
                }
                else
                {
                    arg.fillGetter(b_override, gettersSetters).fillSetter(b_override, gettersSetters);
                }
            }
            std::cout << virtualGettersSetters.str() << gettersSetters.str();
        }
        else
        {
            throw std::runtime_error("-v is mandatory.");
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

    //boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
    //std::cout << "took " << sec.count() << " seconds\n";
    return 0;
    
}
