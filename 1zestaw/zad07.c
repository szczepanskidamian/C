#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char napis[50];
    char znak;
    int count = 0;
	float dlugosc = 0;
    printf("Napisz dowolne zdanie:\n");
    scanf(" %[^\n]", &napis);
	dlugosc = strlen(napis);
    printf("\nWybierz znak zawarty w tekscie: \n", napis);
    scanf(" %c",&znak);
    printf("\nPodany napis: %s\n\nPoszukiwany znak: %c\n\n",napis, znak);

    for (int i=0; i<dlugosc; i++){
        if (napis[i] == znak){
            count = count + 1;
        }
    }
    float czestotliwosc = count/dlugosc*100;
    printf("Czestotliwosc wystepowania znaku: %f%c\nIlosc wystapien: %d\n", czestotliwosc, '%', 
count);
    return 0;   
}
