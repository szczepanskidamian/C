#include <stdio.h>

int nwdr(int a, int b){
	int tmp;
	if (b == 0){
		return a;
	}
	else {
		return nwdr(b, a%b);
	}
}

int nwdi(int a, int b){
	while(a!=b){
		if(a>b){
			a-=b;
		}
		else{
			b-=a;
		}
	}
	return a;
}
