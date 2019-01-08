#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 50

struct ksiazka{
  char *autor;
  char *tytul;
  unsigned ilosc;
  float cena;
};

struct ksiazka magazyn[ROZMIAR];

void usun(unsigned int i)
{
        magazyn[i].autor = NULL;
        magazyn[i].tytul = NULL;
        magazyn[i].ilosc = 0;
        magazyn[i].cena = 0;
}

void swap(struct ksiazka *p1, struct ksiazka *p2)
{
        p1->tytul = malloc(strlen(p2->tytul));
        p1->autor = malloc(strlen(p2->autor));
        strcpy(p1->tytul, p2->tytul);
        strcpy(p1->autor, p2->autor);
        p1->ilosc = p2->ilosc;
        p1->cena = p2->cena;
}

void usunRekord(unsigned int iloscRekordow){//20p
	/*Funkcja usuwa te ksiązki z magazynu,
	których stan wynosi 0 i odpowiednio nadpisuje usuniete rekordy.*/
	for (int i=0; i<ROZMIAR; i++)
	{
		if (magazyn[i].autor == NULL) break;
		if (magazyn[i].ilosc == 0) usun(i);
	}//kasowanie tych z iloscia 0

        for (int i=0; i<ROZMIAR; i++)
        {
                if (magazyn[i].autor != NULL) continue;
                int ni=i;
                for (int j=i+1; j<ROZMIAR; j++)
                {
                        if (magazyn[j].ilosc != 0)
                        {
                                swap(&magazyn[ni++], &magazyn[j]);
                                usun(j);
                        }
                }
        }//nadpisanie pustych rekordow pomiedzy innymi
}

unsigned int obliczIloscLinii(const char *nazwaPliku) {//10p
	/*Funkcja oblicza i zwraca ilosc linii w pliku*/
	unsigned int lines;
	const int max_n = 1000;
	char napis[max_n];

	FILE* plik = fopen(nazwaPliku, "r");
	if (plik == NULL) return 0;

	lines = 0;
	while (fgets(napis, max_n, plik) != NULL)
		lines++;
	return lines;
}

int wypelnijMagazyn(const char *nazwaPliku){//20p
	/*Funkcja czyta plik i wypelnia strukture odpowiednimi danymi*/
	unsigned int iloscRekordow = obliczIloscLinii(nazwaPliku);
	const int max_n = 1000;
	char napis[max_n], *line;
	FILE* plik = fopen(nazwaPliku, "r");
	if (plik == NULL) return -1;
	struct ksiazka *p = magazyn;
    	for (int i=0; i<iloscRekordow-1; i++)
	{
		line = fgets(napis, max_n, plik);
		if (line == NULL) break;
		char *tok = strtok(napis, ";");
		p->tytul = malloc(strlen(tok));
		strcpy(p->tytul, tok);
		tok = strtok(NULL, ";");
		p->autor = malloc(strlen(tok));
		strcpy(p->autor, tok);
		tok = strtok(NULL, ";");
		p->ilosc = atoi(tok);
		tok = strtok(NULL, ";");
		p->cena = atof(tok);
		p++;
	}
	return 0;
}

//wypisz 5p
void wypisz(int skok)
{
        if (skok < 0)
        {
                printf("zly parametr skoku");
                return;        
        }
	for (int i=0; i<ROZMIAR; i+=skok)
	{
                if (magazyn[i].tytul == NULL) continue;
		printf("\n Tytul: %s\n Autor: %s\n Ilosc: %d\n Cena: %f\n", magazyn[i].tytul, magazyn[i].autor, magazyn[i].ilosc, magazyn[i].cena);
	}
}


int porownaj(const void *v1, const void *v2)
{
        struct ksiazka *p1 = (struct ksiazka *) v1;
        struct ksiazka *p2 = (struct ksiazka *) v2;
        return (int)(100.f * p1->cena - 100.f * p2->cena);
}

//sortuj 15p 
void sortuj()
{
        qsort(magazyn, ROZMIAR, sizeof(struct ksiazka), &porownaj);
}


int main(void){

  
	wypelnijMagazyn("lista.txt");
	unsigned int iloscRekordow = obliczIloscLinii("lista.txt");
	wypisz(5);

	usunRekord(iloscRekordow);
        printf("__________\nWypisywanie po usunieciu\n__________\n");
        wypisz(1);

        sortuj();
        printf("__________\nWypisywanie po posortowaniu\n__________\n");
	wypisz(10);
}
