#include <iostream>
#include <string.h>

#define ARRAY_SIZE 16

enum e_mbti_index
{
    INFP,
    INFJ,
    INTP,
    INTJ,
    ISFJ,
    ISFP,
    ISTP,
    ISTJ,
    ENFP,
    ENFJ,
    ENTP,
    ENTJ,
    ESTJ,
    ESTP,
    ESFJ,
    ESFP
};

void insert_to_array(const std::string &input, int *arr)
{
    if (input == "INFP")
        ++arr[INFP];
    else if (input == "INFJ")
        ++arr[INFJ];
    else if (input == "INTP")
        ++arr[INTP];
    else if (input == "INTJ")
        ++arr[INTJ];
    else if (input == "ISFJ")
        ++arr[ISFJ];
    else if (input == "ISFP")
        ++arr[ISFP];
    else if (input == "ISTP")
        ++arr[ISTP];
    else if (input == "ISTJ")
        ++arr[ISTJ];
    else if (input == "ENFP")
        ++arr[ENFP];
    else if (input == "ENFJ")
        ++arr[ENFJ];
    else if (input == "ENTP")
        ++arr[ENTP];
    else if (input == "ENTJ")
        ++arr[ENTJ];
    else if (input == "ESFJ")
        ++arr[ESFJ];
    else if (input == "ESFP")
        ++arr[ESFP];
    else if (input == "ESTP")
        ++arr[ESTP];
    else if (input == "ESTJ")
        ++arr[ESTJ];
}

std::string get_mbti(int idx)
{
    std::string arr[] = {
    "INFP",
    "INFJ",
    "INTP",
    "INTJ",
    "ISFJ",
    "ISFP",
    "ISTP",
    "ISTJ",
    "ENFP",
    "ENFJ",
    "ENTP",
    "ENTJ",
    "ESTJ",
    "ESTP",
    "ESFJ",
    "ESFP"};

    return arr[idx];
}

int get_distance(int a, int b)
{
    std::string a_mbti = get_mbti(a);
    std::string b_mbti = get_mbti(b);
    int dist = 0;

    for (int i = 0; i < 4; ++i)
    {
        if (a_mbti[i] != b_mbti[i])
        {
            ++dist;
        }
    }

    return dist;
}

int find_answer(int *arr)
{
    int ans = __INT32_MAX__;

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        if (arr[i] >= 3)
        {
            return 0;
        }
        --arr[i];
        for (int j = 0; j < ARRAY_SIZE; ++j)
        {
            --arr[j];
            for (int k = 0; k < ARRAY_SIZE; ++k)
            {
                if (arr[i] >= 0 && arr[j] >= 0 && arr[k] > 0)
                {
                    int tmp = get_distance(i, j) + get_distance(j, k) + get_distance(k, i);
                    ans = ans <= tmp ? ans : tmp;
                }
            }
            ++arr[j];
        }
        ++arr[i];
    }

    return ans;
}

int main(void)
{
    int arr[ARRAY_SIZE];
    int t;
    int n;

    std::cin >> t;
    while (t--)
    {
        std::cin >> n;
        memset(arr, 0, sizeof(int) * ARRAY_SIZE);
        while (n--)
        {
            std::string input;

            std::cin >> input;
            insert_to_array(input, arr);            
        }
        std::cout << find_answer(arr) << std::endl;        
    }
    
    return 0;
}
