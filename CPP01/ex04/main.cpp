#include <iostream>
#include <string>
#include <fstream>


void replaceAndWrite(std::string &filename, std::string &s1, std::string &s2)
{
    std::ifstream infile(filename);
    if(!infile.is_open())
    {
        std::cout << "Error: Could not open the file." << std::endl;
        return ;
    }
    std::ofstream outfile(filename+ ".replace");
    if(!outfile)
    {
        std::cout << "Error: Could not open the file." << std::endl;
        return ;
    }
    std::string line;
    size_t len = s1.length();
    while(std::getline(infile, line))
    {
        size_t pos = line.find(s1);
        while(!s1.empty() && pos != std::string::npos)
        {
            outfile << line.substr(0, pos) << s2;
            line = line = line.substr(pos+ len);
            pos = line.find(s1);
        }
        outfile << line << std::endl;
    }
    return  ;
}

int main(int ac, char **av)
{
    if(ac != 4)
    {
        std::cout<<"Not Valid Number of Input!"<<std::endl;
        return 1;
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if(s1.empty() || s2.empty())
    {
        std::cout << "Error: The search string s1 cannot be empty." << std::endl;
        return 1;
    }
    replaceAndWrite(filename, s1, s2);
    return 0;
}

