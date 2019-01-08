#include <stdio.h>
#define ROZMIAR 5

unsigned tablica[ROZMIAR][ROZMIAR];

void wypelnij(){//20p
	/*Funkcja wypelnia macierz kwadratowa po spirali*/
	int maxVal = ROZMIAR * ROZMIAR; 

	int maxX, maxY;
	maxX = maxY = ROZMIAR - 1;

	int minX, minY;
	minX = minY = 0;

	int x, y;
	x = y = 0;
	int xMod, yMod;	
	xMod = 1;
	yMod = 0;
	for (int i=0; i<maxVal; i++)
	{
		tablica[x][y] = i;
		x += xMod;
		y += yMod;
		if (x == maxX && xMod == 1) 
		{
			xMod = 0;	
			yMod = 1;
			maxX -= 1;
			minY ++;
		}
		if (y == maxY && yMod == 1)
		{
			xMod = -1;
			yMod = 0;
			maxY -= 1;
		}
		if (x == minX && xMod == -1)
		{
			xMod = 0;
			yMod = -1;
			minX += 1;
		}
		if (y == minY && yMod == -1)
		{
			xMod = 1;
			yMod = 0;
		}
	}
}


void wyswietl(){//2p
	/*Funkcja wyswietla tablice*/
	for (int i=0; i<ROZMIAR; i++)
	{
		for (int j=0; j<ROZMIAR; j++)
		{
			printf("%d ", tablica[j][i]);
		}
		printf("\n");
	}
}


int obliczSume(){//8p
	/*Funkcja oblicza i zwraca sume elementow na obu przekatnych*/
	int suma = 0;
	for (int i=0; i<ROZMIAR; i++)
		suma += tablica[i][i];
	
	for (int i=0; i<ROZMIAR;i ++)
		suma += tablica[i][ROZMIAR-1-i];

	return suma;
}



int main(void){
	wypelnij();
	wyswietl();
	printf("Sume elementow na obu przekatnych wynosi %d\n", obliczSume());
	return 0;
}
