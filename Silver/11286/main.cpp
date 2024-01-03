#include <cmath>
#include <iostream>

#define HEAP_MAX_SIZE 100000
#define PARENT(x) (((x)-1) / 2)
#define LEFT(x) ((x) * 2 + 1)
#define RIGHT(x) ((x) * 2 + 2)

class AbsoluteHeap
{
private:
    int mData[HEAP_MAX_SIZE];
    int mSize;
    static bool compare(int a, int b);

public:
    AbsoluteHeap();
    ~AbsoluteHeap();
    void Push(int num);
    int Pop();
};

AbsoluteHeap::AbsoluteHeap()
    : mSize(0)
{
}

AbsoluteHeap::~AbsoluteHeap()
{
}

bool AbsoluteHeap::compare(int a, int b)
{
    int abs_a = std::abs(a);
    int abs_b = std::abs(b);
    if (abs_a < abs_b)
        return true;
    else if (abs_a == abs_b)
        return a < b;
    else
        return false;
}

void AbsoluteHeap::Push(int num)
{
    if (mSize == HEAP_MAX_SIZE)
        return;
    int cursor = mSize;
    while (cursor > 0)
    {
        if (AbsoluteHeap::compare(num, mData[PARENT(cursor)]))
        {
            mData[cursor] = mData[PARENT(cursor)];
            cursor = PARENT(cursor);
        }
        else
            break;
    }
    mData[cursor] = num;
    ++mSize;
}

int AbsoluteHeap::Pop()
{
    if (mSize == 0)
        return 0;
    int ret = mData[0];
    int cursor = 0;
    int num = mData[mSize - 1];
    --mSize;
    while (LEFT(cursor) <= mSize - 1)
    {
        if (RIGHT(cursor) > mSize - 1)
        {
            if (AbsoluteHeap::compare(mData[LEFT(cursor)], num))
            {
                mData[cursor] = mData[LEFT(cursor)];
                cursor = LEFT(cursor);
            }
            else
                break;
        }
        else
        {
            if (std::abs(mData[LEFT(cursor)]) < std::abs(mData[RIGHT(cursor)]))
            {
                if (AbsoluteHeap::compare(mData[LEFT(cursor)], num))
                {
                    mData[cursor] = mData[LEFT(cursor)];
                    cursor = LEFT(cursor);
                }
                else
                    break;
            }
            else if (std::abs(mData[LEFT(cursor)]) > std::abs(mData[RIGHT(cursor)]))
            {
                if (AbsoluteHeap::compare(mData[RIGHT(cursor)], num))
                {
                    mData[cursor] = mData[RIGHT(cursor)];
                    cursor = RIGHT(cursor);
                }
                else
                    break;
            }
            else
            {
                if (mData[LEFT(cursor)] < mData[RIGHT(cursor)])
                {
                    if (AbsoluteHeap::compare(mData[LEFT(cursor)], num))
                    {
                        mData[cursor] = mData[LEFT(cursor)];
                        cursor = LEFT(cursor);
                    }
                    else
                        break;
                }
                else
                {
                    if (AbsoluteHeap::compare(mData[RIGHT(cursor)], num))
                    {
                        mData[cursor] = mData[RIGHT(cursor)];
                        cursor = RIGHT(cursor);
                    }
                    else
                        break;
                }
            }
        }
    }
    mData[cursor] = num;
    return ret;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    AbsoluteHeap myHeap;

    std::cin >> n;
    while (n--)
    {
        int input;

        std::cin >> input;
        if (input == 0)
            std::cout << myHeap.Pop() << std::endl;
        else
            myHeap.Push(input);
    }

    return 0;
}
