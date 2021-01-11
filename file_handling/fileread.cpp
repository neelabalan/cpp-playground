#include <fstream>
#include <iostream>
#include <string>

const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

int main(int argc, char **argv)
{
    std::ifstream ifs("todo.md");

    std::string str = "";
    while(getline(ifs, str))
    {
        if((ltrim(str).find("- [ ] ") == 0) || (ltrim(str).find("- [x] ") == 0)) 
        {
            std::cout<<str<<std::endl;
        }
    }
    return 0;
}