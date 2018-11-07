#include <stdio.h>

int moj_strlen(char *str)
{
    int len;
    while (*str != '\0')
    {
        *str++;
        len++;
    }
    return len;
}


int main()
{
    char str[] = "tekst";
    printf("Dlugosc slowa: %s to: %d", str, moj_strlen(str));
    return 0;
}

