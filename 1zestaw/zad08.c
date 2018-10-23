#include <stdio.h>

int main()
{
	int start = 0;
	int end = 100;
	int x;
	int answer;
	printf("Wybierz liczbe od %d do %d\n", start, end);
	scanf(" %d", &x);

	while (1){
		if (start == end){
			printf("Twoja liczba to %d!\n", start);
			return 0;
		}
		int srodek = (start + end) / 2;
		printf("Czy Twoja liczba jest wieksza niz %d? [1=TAK]/[0=NIE]\n", srodek);
		scanf("%d", &answer);
		if (start == end){
			printf("Twoja liczba to %d!\n", start);
		}
		if (answer == 1){
			start = srodek + 1;
		}
		else if (answer == 0){
			end = srodek;
		}
	}
	return 0;
}
