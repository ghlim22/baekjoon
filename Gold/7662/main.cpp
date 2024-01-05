#include <cmath>
#include <iostream>
#define HEAP_MAX_SIZE 100000

class Heap
{
public:
    Heap(bool (*)(int, int));
    ~Heap();
    void Push(int);
    void Pop();
    int Top() const;
    void Print() const;
    void Delete(int);
    bool Empty() const;
    void Clear();
private:
    void heapify(int);
    int find_last_node(int) const;
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
};

class DualPriorityQueue
{
public:
    DualPriorityQueue();
    ~DualPriorityQueue();
    void Push(int);
    void PopMin();
    void PopMax();
    bool Empty() const;
    int Min() const;
    int Max() const;
    void Clear();
private:
    Heap mMaxHeap;
    Heap mMinHeap;
    int mSize;
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

    mData[0] = mData[mSize - 1]; /* move the key at last node to the root */ 
    --mSize;
    heapify(0);
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

/* For BOJ 7662
 * Delete specific key on the heap.
 */
void Heap::Delete(int key)
{
    int cursor = -1;
    int s;

    for (int i = 0; i < mSize; ++i)
    {
        if (mData[i] == key)
        {
            cursor = i;
            break;
        }
    }
    
    if (cursor == -1) /* The key is not in the heap. */
        return;
    
    while (cursor > 0)
    {
        mData[cursor] = mData[parent(cursor)];
        cursor = parent(cursor);
    }
    mData[0] = mData[mSize - 1];
    --mSize;
    heapify(0);
}

bool Heap::Empty() const
{
    return mSize == 0;
}

void Heap::Clear()
{
    mSize = 0;
}

/*
 * i: heapify를 시작할 index
 */
void Heap::heapify(int i)
{
    int num = mData[i];

    while (left(i) <= mSize - 1) /* While i has children */
    {
        if (right(i) > mSize - 1) /* If i has only one child */
        {
            if (mCompare(num, mData[left(i)]))
            {
                mData[i] = mData[left(i)];
                i = left(i);
            }
            else
                break;
        }
        else
        {
            if (mCompare(mData[left(i)], mData[right(i)]))
            {
                if (mCompare(num, mData[right(i)]))
                {
                    mData[i] = mData[right(i)];
                    i = right(i);
                }
                else
                    break;
            }
            else
            {
                if (mCompare(num, mData[left(i)]))
                {
                    mData[i] = mData[left(i)];
                    i = left(i);
                }
                else
                    break;
            }
        }
    }
    mData[i] = num;
}

int Heap::find_last_node(int root) const
{
    int i = root;

    while (i < mSize)
    {
        if (left(i) >= mSize)
            break;
        if (right(i) < mSize)
            i = right(i);
        else
            i = left(i);
    }

    return i;
}

static bool ft_greater(int a, int b)
{
    return a > b;
}

static bool ft_less(int a, int b)
{
    return a < b;
}

DualPriorityQueue::DualPriorityQueue()
    : mMaxHeap(ft_less),
      mMinHeap(ft_greater),
      mSize(0)
{
}

DualPriorityQueue::~DualPriorityQueue()
{
}

void DualPriorityQueue::Push(int num)
{
    mMaxHeap.Push(num);
    mMinHeap.Push(num);
    ++mSize;
}

void DualPriorityQueue::PopMin()
{
    int deleted_key;

    if (mMinHeap.Empty())
        return;
    deleted_key = mMinHeap.Top();
    mMinHeap.Pop();
    mMaxHeap.Delete(deleted_key);
    --mSize;
}

void DualPriorityQueue::PopMax()
{
    int deleted_key;

    if (mMaxHeap.Empty())
        return;
    deleted_key = mMaxHeap.Top();
    mMaxHeap.Pop();
    mMinHeap.Delete(deleted_key);
    --mSize;
}

int DualPriorityQueue::Min() const
{
    if (mSize == 0)
        return 0;
    return mMinHeap.Top();
}

int DualPriorityQueue::Max() const
{
    if (mSize == 0)
        return 0;
    return mMaxHeap.Top();
}

bool DualPriorityQueue::Empty() const
{
    return mSize == 0;
}

void DualPriorityQueue::Clear()
{
    mSize = 0;
    mMinHeap.Clear();
    mMaxHeap.Clear();
}

int main(void)
{
    int t;
    int k;
    char c;
    int num;
    DualPriorityQueue dq;

    std::scanf("%d", &t);
    while (t--)
    {
        std::scanf("%d", &k);
        while (k--)
        {
            std::scanf(" %c", &c);
            std::scanf("%d", &num);
            if (c == 'I')
                dq.Push(num);
            else if (num == -1)
                dq.PopMin();
            else
                dq.PopMax();
        }

        if (dq.Empty())
            std::printf("EMPTY\n");
        else
        {
            std::printf("%d %d\n", dq.Max(), dq.Min());
        }
        dq.Clear();
    }

    return 0;
}
