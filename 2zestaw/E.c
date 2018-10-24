#include <stdio.h>
#include "euklides.h"

int main(){
	int a, b;
	printf("Podaj a i b\n");
	scanf("%d%d", &a, &b);
	printf("NWD: %d\nNWW: %d", nwdr(a, b), (a*b)/nwdr(a,b));
	return 0;	
}
