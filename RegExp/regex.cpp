#include <regex>
#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
    std::regex re(argv[1]);
    std::string line;
    
    while (std::cin.good())
    {
        std::getline(std::cin, line);
        if (std::regex_match(line, re))
        {
            std::cout << line << std::endl;
        }
    }
    return 0;
}

// g++ -o regexcpp regex.cpp 
// ./regexcp
