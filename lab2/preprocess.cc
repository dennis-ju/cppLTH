#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

std::string get_trigram(const std::string s)
{
    int size = s.size() - 2;
    size = (size < 0) ? 0 : size; 
    std::vector<std::string> tri;
    std::string ret{s + " " + std::to_string(size)};

    for(int i = 0; i < size; i++)
    {
        tri.insert(tri.begin(), s.substr(i,3));
    }

    std::sort(tri.begin(), tri.end());
    for(int i = 0; i < size; i++)
    {
        ret = ret + " " + tri[i];
    }
    return ret;
}

int main()
{
    std::ifstream infile("wordlist");
    std::ofstream outfile("words.txt");

    std::string s;
    while(std::getline(infile, s))
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        outfile << get_trigram(s) << '\n';
    }
    infile.close();
    outfile.close();
}