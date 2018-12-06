#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROZMIAR 30

struct ksiazka{
	char autor[32];
	char tytul[63];
	unsigned ilosc;
	float cena;
};

struct ksiazka magazyn[ROZMIAR];
int i;
int wypelnij_strukture(const char *nazwaPliku)
{
	const int max_n = 1000;
	char napis[max_n], *result;
	FILE* ksiazki = fopen(nazwaPliku, "r");
	if (ksiazki == NULL) return -1;
	struct ksiazka *p = magazyn;
    int i=0;
	while (1)
	{
		result = fgets(napis, max_n, ksiazki);
		if (result == NULL) break;

		char * tmp = strtok(napis, ";");
		strcpy(p->tytul, tmp);
		tmp = strtok(NULL, ";");
		strcpy(p->autor, tmp);
		tmp = strtok(NULL, ";");
		p->ilosc = atoi( tmp);
		tmp = strtok(NULL, ";");
		p->cena = atof(tmp);
		p++;
	}
}

int main()
{
	wypelnij_strukture("lista.txt");
	printf("Wybierz jednego z autorów: \n============================================================\n");
	printf("Robin Jarvis \tMercedes Lackey and Andre Norton \n");
	printf("J. K. Rowling \tOrson Scott Card \tDavid Lindsay \n");
	printf("Shirley Jackson \tTad Williams \tRichard Parks \n");
	printf("Tom Holt \tJonathan Stroud \tRick Riordan \n");
	printf("Arthur Machen \tPhilip Pullman \tJ. R. R. Tolkien \n");
	printf("Pat O'Shea \tWilliam Hope Hodgson \tP.C. Cast \n");
	printf("John Bellairs \tDiana Wynne Jones \tN. K. Jemisin \n");
	printf("Suzanne Collins \tBecca Fitzpatrick \tSalman Rushdie  \n");
	printf("============================================================ \n");
	char autor[100];
	scanf("%[^\n]%c", &autor);
	float suma = 0;
	float vat = 0.07;
	for (int i = 0; i<ROZMIAR; i++)
	{
		if (strcmp(magazyn[i].autor, autor) == 0 ){
			suma += magazyn[i].ilosc * magazyn[i].cena;
		}
	}
    suma *= vat;
	printf("Nalezny vat: %f", suma);
	return 0;
}
