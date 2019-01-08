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
/*Funkcja usuwa te ksiązki z magazynu, których stan wynosi 0 i odpowiednio nadpisuje usuniete rekordy.*/
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
//sortuj 15p 

/*void wypisz(int n){
	unsigned int iloscRekordow = obliczIloscLinii("lista.txt");
	int i;
	for (i=1; i<=iloscRekordow; i++){
		if (i % n == 0){
			printf("%s\n", magazyn[i].autor);
		}
	}
}*/

int main(void){
	wypelnijMagazyn("lista.txt");
	unsigned int iloscRekordow = obliczIloscLinii("lista.txt");
	usunRekord(iloscRekordow);
	//printf("Wypisujemy co n-tego autora:\n");
	//wypisz(5);
	printf("\nIlosc linii w pliku: %d\n", iloscRekordow);
	
}
