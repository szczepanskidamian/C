#include <stdio.h>

char *moj_strchr(const char *s, int c)
{
    char litera = (char)c;
    while (*s != litera)
    {
        if (*s == '\0')
        {
            printf("Koniec wyrazu.");
            return 0;
        }
        *s++;
    }
    *s++;
    return (char *)s;
}

int main()
{
    const char s[] = "constant";
    int c = 't';
    puts(moj_strchr(s, c));
    return 0;
}