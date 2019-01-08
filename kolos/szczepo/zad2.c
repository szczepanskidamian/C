#include <stdio.h>
#define ROZMIAR 10

unsigned tablica[ROZMIAR][ROZMIAR];

void wypelnij(){//20p
/*Funkcja wypelnia macierz kwadratowa po spirali*/
	int zwoje = ROZMIAR/2;
	int i, j, curr;
	int liczba = 1;
	for (curr=0; curr<zwoje; curr++){
		for (i = 0 +curr; i<ROZMIAR-curr; i++){
			tablica[i][0+curr] = liczba++;
		}
		for (j = 0+1+curr; j<ROZMIAR-curr; j++){
			tablica[ROZMIAR-1-curr][j] = liczba++;
		}
		for (i = ROZMIAR-2-curr; i>=0+curr; i--){
			tablica[i][ROZMIAR-1-curr] = liczba++;
		}
		for (j = ROZMIAR-2-curr; j>0+curr; j--){
			tablica[0+curr][j] = liczba++;
		}
	}
	if (ROZMIAR % 2 != 0){
		tablica[zwoje][zwoje] = ROZMIAR*ROZMIAR;
	}
}


void wyswietl(){//2p
/*Funkcja wyswietla tablice*/
	printf("\n\nWYSWIETL\n");
	int i=0 , j=0;
	for (i=0; i<ROZMIAR; i++){
		for (j=0; j<ROZMIAR; j++){
			printf("%d ", tablica[i][j]);
		}
		printf("\n");
}
}


int obliczSume(){//8p
/*Funkcja oblicza i zwraca sume elementow na obu przekatnych*/
	int i, j;
	int suma=0;
	for (i=0; i<ROZMIAR; i++){
		suma += tablica[i][i];
	}

	for (i=ROZMIAR-1; i>=0; i--){
		suma += tablica[ROZMIAR-1-i][i];
	}

	return suma;
}



int main(void){
wypelnij();
wyswietl();
printf("Sume elementow na obu przekatnych wynosi %d\n", obliczSume());
if(!2){
	printf("TRU");
}
else if(1){
	printf("%d", 1);

}
else if(0){
	printf("%d", 0);

}
return 0;
}
