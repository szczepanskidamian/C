#include <stdio.h>

int main(){
	int x;
	int i=0;
	for (i; i<=10; i++){
		x = i*(i*(i*(i*(i*(i*(3*i))))+1)-9)+16;
		printf("Dla i = %d wynik to: %d\n", i, x);
	}
	
	return 0;
}
