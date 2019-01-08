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

void usunRekord(unsigned int iloscRekordow){//20p
	struct ksiazka * p = magazyn;
	int i = 0;
	for(; i < iloscRekordow; i++){
		if (p->ilosc == 0){
			p->autor = NULL;
			p->tytul = NULL;
			p->cena = 0;

			if (i == iloscRekordow - 1) { continue; }
			else {
				magazyn[i] = magazyn[iloscRekordow];
				iloscRekordow -= 1;
				i--;
			}
		}		

		p++;
	}
}

unsigned int obliczIloscLinii(const char *nazwaPliku) {//10p
  /*Funkcja oblicza i zwraca ilosc linii w pliku*/
  unsigned int lines = 0;
    char linia[100];
    FILE * plik = fopen(nazwaPliku, "r");
    if (plik == NULL){
	printf("Blad wczytywania pliku\n");
	return 0;
    }
    else{
        while(fgets(linia, 100, plik) != NULL){
	    lines++;
	}
    }
  return lines;
}

int wypelnijMagazyn(const char *nazwaPliku){//20p
	char napis[100], *result;
	FILE* plik = fopen(nazwaPliku, "r");
	if (plik == NULL){
		printf("Blad wczytywania pliku\n");	
		return -1;
	}
	struct ksiazka *p = magazyn;
	while ((result = fgets(napis, 100, plik)))
	{
		char * temp = strtok(napis, ";");

		strcpy(p->tytul, temp);
		//p->tytul[sizeof(p->tytul)] = '\0';
		temp = strtok(NULL, ";");
		strcpy(p->autor, temp);
		//p->tytul[sizeof(p->autor)] = '\0';
		temp = strtok(NULL, ";");
		p->ilosc = atoi(temp);
		temp = strtok(NULL, ";");
		p->cena = atof(temp);

		p++;
	}
    return 0;
}

void wypisz(int n){
     //wypisz 5p
     if (n < 1) {printf("n musi byc wieksze od 0!"); return;}
     int i;
     for (i = 1; i < ROZMIAR; i += n){
         printf("%s\n", magazyn[i].autor);
     }
}

int compare(const void *k1, const void *k2){
  struct ksiazka *p1 = (struct ksiazka *)k1;
  struct ksiazka *p2 = (struct ksiazka *)k2;
  if (p1->cena > p2->cena) return 1;
  if (p1->cena < p2->cena) return -1;
  return 0;
}

void sortuj(){
	//sortuj 15p
    	qsort(magazyn, ROZMIAR, sizeof(struct ksiazka), &compare);
}

int main(void){

  printf("Zadanie 1\n");
  wypelnijMagazyn("lista.txt");
  unsigned int iloscRekordow = obliczIloscLinii("lista.txt");
  printf("Ilosc rekordow: %d\n", iloscRekordow);
  //wypisz(5);
  usunRekord(iloscRekordow);
  //wypisz(1);
  sortuj();
  //wypisz(10);

}
