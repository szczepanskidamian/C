#include <stdio.h>
#include <ctype.h>
#define DL = 60

unsigned litery['Z' - 'A' + 1];

void czytaj()
{   
    printf("Napisz dowolne zdanie:\n");
    int c;
    while ( (c = getchar()) != '\n')
    {
        if (isalpha(c))
        {
            litery[toupper(c) - 'A']++;
        }
    }
}

void wyswietl()
{
    int i;
    for (i ='A'; i <= 'Z'; i++)
    {
        printf("%c %d\t", i, litery[i-'A']);
        for (int j=0; j <= litery[i-'A']; j++)
        {
            printf("@");
        }
        printf("\n");
    }
}

int main()
{   
    czytaj();
    wyswietl();
    return 0;
}