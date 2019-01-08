#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROZMIAR 30

struct ksiazka{
	char autor[33];	//33, a nie 32 bo najdluzszy autor sie nie miesci
	char tytul[63];
	unsigned ilosc;
	float cena;
};

struct ksiazka magazyn[ROZMIAR];

int wypelnij_strukture(const char *nazwaPliku)
{
	const int max_n = 1000;
	char napis[max_n], *result;
	FILE* plik = fopen(nazwaPliku, "r");
	if (plik == NULL){
		printf("Nie znaleziono pliku\n");	
		return -1;
	}
	struct ksiazka *p = magazyn;	//wskaźnik na pierwszy element tablicy
	while ((result = fgets(napis, max_n, plik))) //dopoki result != NULL
	{
		char * temp = strtok(napis, ";");

		strcpy(p->tytul, temp);
		temp = strtok(NULL, ";");
		strcpy(p->autor, temp);
		temp = strtok(NULL, ";");
		p->ilosc = atoi(temp);
		temp = strtok(NULL, ";");
		p->cena = atof(temp);

		p++;	//przesuwamy wskaźnik na następną książkę w tablicy 
	}
	return 0;
}

int main()
{
	if(wypelnij_strukture("lista.txt") == -1) return -1;
	int i;
	for (i = 0; i<ROZMIAR; i++)
	{
		puts(magazyn[i].autor);
		puts(magazyn[i].tytul);
		putchar('\n');
	}
	return 0;
}