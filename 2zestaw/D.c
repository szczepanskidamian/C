#include <stdio.h>
#include "euklides.h"

int main(){
	int a;
	int b;
	printf("Podaj a i b\n");
	scanf("%d%d", &a, &b);
	printf("Rekurencyjnie: %d\n",nwdr(a, b));
	printf("Iteracyjnie: %d\n", nwdi(a, b));
	return 0;
}


