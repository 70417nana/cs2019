#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void getDisjoint(int N, bool **tmp)
{
    int i, j, k;
    tmp = (bool **)calloc(N + 1, sizeof(bool *));
    for (i = 0; i <= N + 1; i++)
    {
        tmp[i] = (bool *)calloc(N + 1, sizeof(bool));
    }
    printf("allocated memory \n");
    //1‚Å‰Šú‰»
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            tmp[i][j] = true;
        }
    }
    for (i = 1; i <= N; ++i)
    {
        for (j = i; j <= N; ++j)
        {
            if (!tmp[i][j])
            {
                continue;
            }
            for (k = 2; j * k <= N; ++k)
            {
                tmp[i * k][j * k] = 0;
                tmp[j * k][i * k] = 0;
            }
        }
    }
    for (i = 1; i <= N; ++i)
    {
        for (j = 1; j <= N; ++j)
        {
            printf("%2d", tmp[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    bool **b;
    printf("getGCD\n");
    getDisjoint(N, b);
    return 0;
}