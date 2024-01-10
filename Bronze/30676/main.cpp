#include <iostream>

int main(void)
{
    int n;

    std::cin >> n;

    if (n < 425)
        std::cout << "Violet\n";
    else if (n < 450)
        std::cout << "Indigo\n";
    else if (n < 495)
        std::cout << "Blue\n";
    else if (n < 570)
        std::cout << "Green\n";
    else if (n < 590)
        std::cout << "Yellow\n";
    else if (n < 620)
        std::cout << "Orange\n";
    else
        std::cout << "Red\n";
    
    return 0;
}