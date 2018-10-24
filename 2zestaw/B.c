#include <stdio.h>
#include <stdlib.h>
#define ARGS 10
#define X0 -5.0f
#define X1 5.0f
#define Y0 -4.0f
#define Y1 4.0f
#define SIZEX 20.0f
#define SIZEY 80.0f


int main(){
	float a, b, c;
	int i, j, inty;
	float y, x, dl;
	float stepx;
	float stepy; 
	
	stepy = (Y1-Y0)/SIZEY;
	stepx = (X1-X0)/SIZEX;
	printf("podaj wspolczynniki a b i c\n");
	scanf("%f%f%f", &a, &b, &c);
	for (i = 0; i <= SIZEX; i++){
		x = X0 + i*stepx;
		y = c + x*(a*x + b);
		dl = (y - Y0)/stepy;
		for (j=0; j < (int)y; j++) putchar(' ');
		putchar('*');
		putchar('\n');
	} 	
	return 0;
}
