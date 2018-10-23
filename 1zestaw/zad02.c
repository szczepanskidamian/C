#include <stdio.h>

float main()
{
	float x;
	float y;
	char znak;
	float wynik;

	printf("pierwsza liczba: \n");
	scanf("%f", &x);
	printf("druga liczba: \n");
	scanf("%f", &y);
	printf("znak operacji: \n");
	scanf("%c", &znak);
	scanf("%c", &znak);

	if (znak == '+'){
		wynik = x+y;
		printf("Wynik: %f\n", wynik);
	} 
	else if (znak == '-'){
		wynik = x-y;
		printf("Wynik: %f\n", wynik);
	}
	else if (znak == '*'){
		wynik = x*y;
		printf("Wynik: %f\n", wynik);
	}
	else if (znak == '/'){
		if (y == 0){
			printf("Nie mozna dzielic przez 0.");
		}
		else {
			wynik = x/y;
			printf("Wynik : %f\n", wynik);
		}
	}
	return 0;
}
