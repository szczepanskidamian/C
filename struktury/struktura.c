#include <stdio.h>
#include <string.h>
#define ROZMIAR 3

struct ksiazka{
  char autor[40];                                                                                                     
  char tytul[63];                                                                                                     
  unsigned ilosc;                                                                                                     
  float cena;                                                                                                         
};                                                                                                                    
                                                                                                                      
struct ksiazka magazyn[ROZMIAR];

int main(void)
{   
    int i;
    const int max_n = 100;
    char napis[max_n], *result;
    char *token;
    FILE *fp = fopen("C:/Projekty/C/struktury/lista.txt", "r");
    fseek(fp, 0L, SEEK_END);
    const int linie = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    for (i = 1; i <= linie; ++i)
    {
        result = fgets(napis, max_n, fp);
        if (result != NULL)
        {
            if (feof (stdin))
            {
                printf ("\n%d koniec pliku\n", i);
            }
            else
            {
                token = strtok(napis, ";");
                strcpy(magazyn[i-1].tytul, token);
                token = strtok(NULL, ";");
                strcpy(magazyn[i-1].autor, token);
                token = strtok(NULL, ";");
                magazyn[i-1].ilosc = atoi(token);
                token = strtok(NULL, ";");
                magazyn[i-1].cena = atof(token);
                token = strtok(NULL, ";");
                printf("%s\n", magazyn[i-1].tytul);
            }
        }
    }
    return 0;
}