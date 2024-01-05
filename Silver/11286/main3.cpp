#include <cmath>
#include <iostream>

#define HEAP_MAX_SIZE 100000

class Heap
{
private:
    int mData[HEAP_MAX_SIZE];
    int mSize;
    bool (*mCompare)(int, int);
    /* 이 비교함수를 이용해 heapify를 수행한다.
     * 요소를 추가할 때는 cmp(new key, parent.key) == true 이면 parent와 swap하면서
     * 올라간다.
     * top를 제거할 때는 기존 heap의 마지막 요소를 root로 올리고, 자식 중 cmp(l, r)을 했을
     * 때, true이면 r과 비교하고 아니면 l과 비교한다.
     * cmp(num, chlid) == true 이면 swap하면서 내려간다.
     */

public:
    Heap(bool (*)(int, int));
    ~Heap();
    void Push(int);
    void Pop();
    int Top() const;
    void Print() const;
};

inline int parent(int i)
{
    return (i - 1) / 2;
}

inline int left(int i)
{
    return i * 2 + 1;
}

inline int right(int i)
{
    return i * 2 + 2;
}

Heap::Heap(bool (*cmp)(int, int))
    : mSize(0), mCompare(cmp)
{
}

Heap::~Heap()
{
}

void Heap::Push(int num)
{
    int cursor;

    if (mSize == HEAP_MAX_SIZE) /* If the heap is full. */
        return;
    cursor = mSize;
    while (cursor > 0)
    {
        if (mCompare(mData[parent(cursor)], num))
        {
            mData[cursor] = mData[parent(cursor)];
            cursor = parent(cursor);
        }
        else
            break;
    }
    mData[cursor] = num;
    ++mSize;
}

void Heap::Pop()
{
    int cursor;
    int num;

    if (mSize == 0)
        return;

    cursor = 0;
    num = mData[mSize - 1]; /* Move the last node to the root */
    --mSize;

    while (left(cursor) <= mSize - 1) /* While cursor has children */
    {
        if (right(cursor) > mSize - 1) /* If cursor has only one child */
        {
            if (mCompare(num, mData[left(cursor)]))
            {
                mData[cursor] = mData[left(cursor)];
                cursor = left(cursor);
            }
            else
                break;
        }
        else
        {
            if (mCompare(mData[left(cursor)], mData[right(cursor)]))
            {
                if (mCompare(num, mData[right(cursor)]))
                {
                    mData[cursor] = mData[right(cursor)];
                    cursor = right(cursor);
                }
                else
                    break;
            }
            else
            {
                if (mCompare(num, mData[left(cursor)]))
                {
                    mData[cursor] = mData[left(cursor)];
                    cursor = left(cursor);
                }
                else
                    break;
            }
        }
    }
    mData[cursor] = num;
}

int Heap::Top() const
{
    if (mSize == 0)
        return 0;
    return mData[0];
}

void Heap::Print() const
{
    for (int i = 0; i < mSize; ++i)
        std::printf("[%d]: %d\n", i, mData[i]);
    std::printf("\n");
}

bool absolute_cmp(int a, int b)
{
    if (std::abs(a) == std::abs(b))
        return a > b;
    return std::abs(a) > std::abs(b);
}

int main(void)
{
    Heap h(absolute_cmp);
    int n;
    int x;

    std::scanf("%d", &n);
    while (n--)
    {
        std::scanf("%d", &x);
        if (x == 0)
        {
            std::printf("%d\n", h.Top());
            h.Pop();
        }
        else
        {
            h.Push(x);
        }
    }

    return 0;
}
