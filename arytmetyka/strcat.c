#include <stdio.h>

char *moj_strcat(char *dokad, const char *skad)
{
    while (*dokad != '\0')
    {
        *dokad++;
    }
    while (*skad != '\0')
    {
        *dokad++ = *skad++;
    }
    *dokad = '\0';
    return (char *)dokad;
    
}

int main()
{
    char dokad[] = "Hello";
    char skad[] = "World";
    char result = moj_strcat(dokad, skad);
    puts(dokad);
    return 0;
}