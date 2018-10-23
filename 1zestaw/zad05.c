#include <stdio.h>

int main(){
	int i;
	int min;
	int max;
	printf("podaj liczbe:\n");
	scanf("%d", &i);
	if (i < 0){
		printf("Brak minimum i maksimum.");
		return 0;
	}
	else{
		min = i;
		max = i;
	}
	while (1){
		printf("podaj liczbe:\n");
		scanf("%d", &i);
		if (i < 0){
			printf("min: %d\t max: %d\n", min, max);
			break;
		}
		if (i > max){
			max = i;
		}
		if (i < min){
			min = i;
		}
	}

	return 0;
}
