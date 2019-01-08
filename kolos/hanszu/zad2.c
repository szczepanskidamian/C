#include <stdio.h>
#define ROZMIAR 3

unsigned tablica[ROZMIAR][ROZMIAR];

void wypelnij(){//20p
	int len = ROZMIAR, k = 1, p = 0, i;					
		while(k<=ROZMIAR*ROZMIAR)                      
		{
			for(i=p;i<len;i++)        tablica[p][i]=k++;
			for(i=p+1;i<len;i++)      tablica[i][len-1]=k++;
			for(i=len-2;i>=p;i--)     tablica[len-1][i]=k++;
			for(i=len-2;i>p;i--)      tablica[i][p]=k++;
			p++, len = len-1;
		
		}

		if(!ROZMIAR%2)
			tablica[(ROZMIAR+1)/2][(ROZMIAR+1)/2]=ROZMIAR*ROZMIAR; 

	}




void wyswietl(){//2p
	int i, j;
	for(i = 0; i < ROZMIAR; i++){
		for (j = 0; j < ROZMIAR; j++){
			printf("%u  ", tablica[i][j]);		
		}
		printf("\n");
	}
}


int obliczSume(){//8p
	int i, sum;
	sum = 0;
	for (i = 0; i < ROZMIAR; i++) {sum += tablica[i][i];}	
	for (i = 0; i < ROZMIAR; i++) {sum += tablica[ROZMIAR-1 - i][i];}
	return sum;
}

int main(void){
	wypelnij();
	wyswietl();
	printf("\nSume elementow na obu przekatnych wynosi %d\n", obliczSume());
	return 0;
}
