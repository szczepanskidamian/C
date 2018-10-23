#include <stdio.h>
#include <math.h>

int main(){

	int i;
	int n;
	int p;
	n = 2;
	i = 1;
	for (i;i <= 16; i++){
		p = pow(n, i);
		printf("2 ^ %d = %d\n", i, p);
	}
	return 0;
}

