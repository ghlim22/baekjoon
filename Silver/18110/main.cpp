#include <iostream>

int my_ceiling(double n)
{
    return (int)(n * 0.15 + 0.5);
}

int main(void)
{
    int difficulties[31] = {0, };
    int n;
    int trimmed_points;
    int difficulty;
    int tmp;

    std::cin >> n;
    trimmed_points = my_ceiling((double)n);

    if (n == 0)
    {
        std::cout << "0" << std::endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> difficulty;
        ++difficulties[difficulty];
    }

    tmp = trimmed_points;
    for (int i = 1; i <= 30; ++i)
    {
        if (difficulties[i] > tmp)
        {
            difficulties[i] -= tmp;
            tmp = 0;
            break;
        }
        else if (difficulties[i] > 0)
        {
            tmp -= difficulties[i];
            difficulties[i] = 0;
        }

        if (tmp == 0)
        {
            break;
        }
    }

    tmp = trimmed_points;
    for (int i = 30; i >= 1; --i)
    {
        if (difficulties[i] > tmp)
        {
            difficulties[i] -= tmp;
            tmp = 0;
            break;
        }
        else if (difficulties[i] > 0)
        {
            tmp -= difficulties[i];
            difficulties[i] = 0;
        }

        if (tmp == 0)
        {
            break;
        }
    }

    double mean = 0.0;
    int n_trimmed = 0;
    for (int i = 1; i <= 30; ++i)
    {
        n_trimmed += difficulties[i];
        mean += difficulties[i] * i;
    }
    std::cout << (int)(mean / n_trimmed + 0.5) << std::endl;

    return 0;
}
