#include <iostream>
#include <sstream>
#include <string>

int main(void)
{
    int n;
    std::string line;
    std::string word;

    std::cin >> n;
    std::cin.ignore();
    while (n--) {
        std::getline(std::cin, line);
        std::istringstream isstream(line);
        while (isstream >> word) {
            for (int i = 0; i < word.size(); ++i) {
                std::cout << word[word.size() - 1 - i];
            }
            if (isstream.eof()) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }

    return 0;
}
