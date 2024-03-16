#include <random>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <conio.h>

void matrics(int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == 0 || j == n - 1)
            {
                printf("#");
            }
            if (i == 0 || i == n - 1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main()
{

    matrics(20);
    return 0;
}