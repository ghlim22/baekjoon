#include <iostream>
#include <string>

int queue[10000];
int front = 0;
int back = 0;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n;
    std::string cmd;

    std::cin >> n;
    while (n--) {
        std::cin >> cmd;
        if (cmd == "push") {
            int num;
            std::cin >> num;
            queue[back++] = num;
        } else if (cmd == "pop") {
            if (front == back) {
                std::cout << -1 << '\n';
            } else {
                std::cout << queue[front++] << '\n';
            }
        } else if (cmd == "size") {
            std::cout << back - front << '\n';
        } else if (cmd == "empty") {
            if (front == back) {
                std::cout << 1 << '\n';
            } else {
                std::cout << 0 << '\n';
            }
        } else if (cmd == "front") {
            if (front == back) {
                std::cout << -1 << '\n';
            } else {
                std::cout << queue[front] << '\n';
            }
        } else if (cmd == "back") {
            if (front == back) {
                std::cout << -1 << '\n';
            } else {
                std::cout << queue[back - 1] << '\n';
            }
        }
    }

    return 0;
}
