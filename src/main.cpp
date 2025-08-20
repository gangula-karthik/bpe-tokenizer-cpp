#include <iostream>
#include <fstream>
#include <iterator>
#include <boost/regex.hpp>
#include <string>
using namespace std;



std::vector<std::string> resplit(const std::string &s, const boost::regex &sep_regex = boost::regex{"\\s+"}) {
  boost::sregex_token_iterator iter(s.begin(), s.end(), sep_regex, -1);
  boost::sregex_token_iterator end;
  for (; iter != end; ++iter) {
    std::cout << "Match: '" << iter->str() << "'\n";
    }
    return {iter, end};
}


int main () {
    std::string filename = "../oscar_10k.txt";
    std::ifstream istrm(filename, std::ios::binary);

    if (!istrm.is_open())
        std::cout << "failed to open " << filename << '\n';

    else {
        std::string line;
        int count = 0;
        std::string pattern = R"('s|'t|'re|'ve|'m|'ll|'d| ?[a-zA-Z]+| ?[0-9]+| ?[^\s\w]+|\s+)";
        boost::regex sep_regex(pattern);

        while (std::getline(istrm, line) && count < 5) {
            boost::regex token_regex(pattern);
            boost::sregex_iterator iter(line.begin(), line.end(), token_regex);
            boost::sregex_iterator end;
            
            for (; iter != end; ++iter) {
                if (!iter->str().empty()) {
                    std::cout << "'" << iter->str() << "' ";
                }
            }
            
            std::cout << std::endl;
            ++count;
        }
    }
}