#include <iostream>

int main(void)
{
    int n;
    std::string line;

    std::cin >> n;
    while (n--) {
        std::cin >> line;
        int indi = 0;
        bool bSuccess = true;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '(') {
                indi++;
            } else if (indi == 0) {
                bSuccess = false;
                break;
            } else {
                indi--;
            }
        }
        if (bSuccess && indi == 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
