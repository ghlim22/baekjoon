#include <iostream>
#include <stack>
#include <stdlib.h>

int main(void)
{
    std::stack<int> plus_stack;
    std::stack<int> minus_stack;
    std::stack<char> op_stack;
    char eq[51];
    char c;
    char *s;
    char *e;
    int a;
    int b;
    int sum = 0;

    scanf("%s", eq);
    s = eq;
    while (1)
    {
        plus_stack.push((int)strtol(s, &e, 10));
        if (*e == '\0')
            break;
        op_stack.push(*e);
        s = e + 1;
    }
    while (!op_stack.empty())
    {
        c = op_stack.top();
        op_stack.pop();
        if (c == '+')
        {
            a = plus_stack.top();
            plus_stack.pop();
            b = plus_stack.top();
            plus_stack.pop();
            plus_stack.push(b + a);
        }
        else
        {
            minus_stack.push(-(plus_stack.top()));
            plus_stack.pop();
        }
    }
    while (!plus_stack.empty())
    {
        sum += plus_stack.top();
        plus_stack.pop();
    }
    while (!minus_stack.empty())
    {
        sum += minus_stack.top();
        minus_stack.pop();
    }
    printf("%d\n", sum);
    return (0);
}