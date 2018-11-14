#include <stdio.h>
#define X 9

int tabela[X][X] = {};
int i = 1;
int aktualny_zwoj= 0;
int zwoje = X/2;

void printSpiral(int m)
{
    for (int j = 0 + m; j <= X -1 - m; j++)
    {
        tabela[m][j] = i++;
    }
    for (int j = 1 + m; j <= X -1 - m; j++)
    {
        tabela[j][X-1-m] = i++;
    }
    for (int j = X -2 - m; j >= 0 + m; j--)
    {
        tabela[X -1 -m][j] = i++;
    }
    for (int j = X -2 - m; j > 0 + m; j--)
    {
        tabela[j][m] = i++;
    }
}

int main()
{
    for (aktualny_zwoj; aktualny_zwoj < zwoje; aktualny_zwoj++)
    {
        printSpiral(aktualny_zwoj);
    }
    if (X%2 != 0)
    {
        tabela[zwoje][zwoje] = X*X;
    }
    for (i = 0; i < X; i++)
    {
        for (int j = 0; j < X; j++)
        {
            printf("%d\t ", tabela[i][j]);
        }
        printf("\n");
    }
    return 0;
}