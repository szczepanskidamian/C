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
	unsigned int lines=0;
	int ch = 0;
	FILE *fp = fopen(nazwaPliku, "r");
	if (fp == NULL){
		return 0;
	}
	while ((ch = fgetc(fp)) != EOF){
		if (ch == '\n'){
			lines++;
		}
	}
	fclose(fp);
  	return lines;
}

int wypelnijMagazyn(const char *nazwaPliku){//20p
    /*Funkcja czyta plik i wypelnia strukture odpowiednimi danymi*/
	unsigned int iloscRekordow = obliczIloscLinii(nazwaPliku);
	int i;
	char napis[200];
	char *result;
	char *token;
	FILE *fp = fopen(nazwaPliku, "r");
	for (i = 1; i <= iloscRekordow; ++i){
		result = fgets(napis, 200, fp);
		if (result != NULL){
		        token = strtok(napis, ";");\
			magazyn[i-1].tytul = malloc(strlen(token));
		        strcpy(magazyn[i-1].tytul, token);
		        token = strtok(NULL, ";");
			magazyn[i-1].autor = malloc(strlen(token));
		        strcpy(magazyn[i-1].autor, token);
		        token = strtok(NULL, ";");
		        magazyn[i-1].ilosc = atoi(token);
		        token = strtok(NULL, ";");
		        magazyn[i-1].cena = atof(token);
		        token = strtok(NULL, ";");
		        printf("%s\n", magazyn[i-1].tytul);
		}
		else{
			printf("------KONIEC PLIKU------");
			return 0;		
		}
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

//sortuj 15p 
int compare(const void *k1, const void *k2){
  struct ksiazka *p1 = (struct ksiazka *)k1;
  struct ksiazka *p2 = (struct ksiazka *)k2;
  if (p1->cena > p2->cena) return 1;
  if (p1->cena < p2->cena) return -1;
  return 0;
}

void sortuj(){
    	qsort(magazyn, ROZMIAR, sizeof(struct ksiazka), &compare);
}

int main(void){
	wypelnijMagazyn("lista.txt");
	unsigned int iloscRekordow = obliczIloscLinii("lista.txt");
	usunRekord(iloscRekordow);
	//printf("Wypisujemy co n-tego autora:\n");
	wypisz(5);
	sortuj();
	printf("---------------POSORTOWANE---------------\n");
	wypisz(5);
	printf("\nIlosc linii w pliku: %d\n", iloscRekordow);
	return 0;
}
