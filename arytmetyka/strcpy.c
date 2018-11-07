#include <stdio.h>

char zrodlo[] = "Tekst zrodlowy";
char kopia[] = {};

void moj_strcpy(char *kopia, char *zrodlo)
{
    if (*zrodlo == '\0')
    {
        printf("Nie wprowadzono wyrazu");
        return ;
    }
    while (*zrodlo != '\0')
    {
        *kopia++ = *zrodlo++;
    }
    *kopia = '\0';
}

int main()
{   
    printf("Zrodlo: %s", zrodlo);
    moj_strcpy(kopia, zrodlo);
    printf("\nKopia: %s", kopia);
    return 0;
}
