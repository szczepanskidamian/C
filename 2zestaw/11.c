#include <stdio.h>
#include <math.h>

int main()
{   
    char c;
    int char_size = 8;
    short s;
    long l;
    long long ll;
    signed si;
    unsigned unsi;

    int i;
    printf("CHAR rozmiar: %lu, zakres : %0.0f do %0.0f\n", sizeof(c) * char_size, -pow(2, sizeof(c) * char_size)/2, (pow(2, sizeof(c) * char_size)/2)-1);
    printf("SHORT rozmiar: %lu, zakres : %0.0f do %0.0f\n", sizeof(s) * char_size, -pow(2, sizeof(s) * char_size)/2, (pow(2, sizeof(s) * char_size)/2)-1);
    printf("INT rozmiar: %lu, zakres : %0.0f do %0.0f\n", sizeof(i) * char_size, -pow(2, sizeof(i) * char_size)/2, (pow(2, sizeof(i) * char_size)/2)-1);
    printf("LONG rozmiar: %lu, zakres : %0.0f do %0.0f\n", sizeof(l) * char_size, -pow(2, sizeof(l) * char_size)/2, (pow(2, sizeof(l) * char_size)/2)-1);
    printf("LONG LONG rozmiar: %lu, zakres : %0.0f do %0.0f\n", sizeof(ll)* char_size, -pow(2, sizeof(ll) * char_size)/2, (pow(2, sizeof(ll) * char_size)/2)-1);
    printf("SIGNED rozmiar: %lu, zakres : %0.0f do %0.0f\n", sizeof(si) * char_size, -pow(2, sizeof(si) * char_size)/2, (pow(2, sizeof(si) * char_size)/2)-1);
    printf("UNSIGNED rozmiar: %lu, zakres : 0 do %0.0f\n", sizeof(unsi) * char_size, (pow(2, sizeof(unsi) * char_size)/2));
    printf("CHAR rozmiar: %lu, zakres : 0 do %0.0f\n", sizeof(c) * char_size, pow(2, sizeof(c) * char_size)/2);
    printf("SHORT rozmiar: %lu, zakres : 0 do %0.0f\n", sizeof(s) * char_size, pow(2, sizeof(s) * char_size)/2);
    printf("INT rozmiar: %lu, zakres : 0 do %0.0f\n", sizeof(i) * char_size, pow(2, sizeof(i) * char_size)/2);
    printf("LONG rozmiar: %lu, zakres : 0 do %0.0f\n", sizeof(l) * char_size, pow(2, sizeof(l) * char_size)/2);
    


    return 0;
}
