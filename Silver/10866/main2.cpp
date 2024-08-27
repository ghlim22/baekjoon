#include <iostream>
#include <string>

#define SIZE (10000)
int deque[SIZE * 2 + 2];
int front = SIZE;
int back = SIZE;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n;
    int size = 0;
    std::string cmd;

    std::cin >> n;
    while (n--) {
        std::cin >> cmd;
        if (cmd == "push_front") {
            int num;
            std::cin >> num;
            if (front == back) {
                ++back;
            }
            deque[front--] = num;
            ++size;
        } else if (cmd == "push_back") {
            int num;
            std::cin >> num;
            if (front == back) {
                --front;
            }
            deque[back++] = num;
            ++size;
        } else if (cmd == "pop_front") {
            if (size == 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << deque[++front] << '\n';
                --size;
            }
        } else if (cmd == "pop_back") {
            if (size == 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << deque[--back] << '\n';
                --size;
            }
        } else if (cmd == "size") {
            std::cout << size << '\n';
        } else if (cmd == "empty") {
            if (size == 0) {
                std::cout << 1 << '\n';
            } else {
                std::cout << 0 << '\n';
            }
        } else if (cmd == "front") {
            if (size == 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << deque[front + 1] << '\n';
            }
        } else if (cmd == "back") {
            if (size == 0) {
                std::cout << -1 << '\n';
            } else {
                std::cout << deque[back - 1] << '\n';
            }
        }
    }

    return 0;
}
