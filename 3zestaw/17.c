#include <stdio.h>
#include <ctype.h>

unsigned litery1['Z' - 'A' + 1];
unsigned litery2['Z' - 'A' + 1];

int main()
{   
    printf("Napisz pierwszy wyraz:\n");
    int c;
    int d;
    while ( (c = getchar()) != '\n')
    {
        if (isalpha(c))
        {
            litery1[toupper(c) - 'A']++;
        }
    }    
    printf("Napisz drugi wyraz:\n");
    while ( (d = getchar()) != '\n')
    {
        if (isalpha(d))
        {
            litery2[toupper(d) - 'A']++;
        }
    }
    for (int i ='A'; i <= 'Z'; i++)
    {
        if (litery1[i-'A']++ != litery2[i-'A']++){
            printf("NIE");
            return 0;
        }
    }
    printf("TAK");
    return 0;
}
