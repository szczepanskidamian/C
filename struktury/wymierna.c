#include <stdio.h>

typedef struct {
    int liczebnik;
    int mianownik;
} wymierna;

void wypisz(wymierna liczba){
    printf("%d/%d\n", liczba.liczebnik, liczba.mianownik);
}

void sum(wymierna liczba1, wymierna liczba2){
    if (liczba1.mianownik != liczba2.mianownik){
        int tmp_mian = liczba1.mianownik;
        liczba1.mianownik *= liczba2.mianownik;
        liczba1.liczebnik *= liczba2.mianownik;
        liczba2.mianownik *= tmp_mian;
        liczba2.liczebnik *= tmp_mian;
    }
    wymierna wynik;
    wynik.liczebnik = liczba1.liczebnik + liczba2.liczebnik;
    wynik.mianownik = liczba1.mianownik;
    wypisz(wynik);
}

void sub(wymierna liczba1, wymierna liczba2){
    if (liczba1.mianownik != liczba2.mianownik){
        int tmp_mian = liczba1.mianownik;
        liczba1.mianownik *= liczba2.mianownik;
        liczba1.liczebnik *= liczba2.mianownik;
        liczba2.mianownik *= tmp_mian;
        liczba2.liczebnik *= tmp_mian;
    }
    wymierna wynik;
    wynik.liczebnik = liczba1.liczebnik - liczba2.liczebnik;
    wynik.mianownik = liczba1.mianownik;
    wypisz(wynik);    
}

void mul(wymierna liczba1, wymierna liczba2){
    wymierna wynik;
    wynik.liczebnik = liczba1.liczebnik * liczba2.liczebnik;
    wynik.mianownik = liczba1.mianownik * liczba2.mianownik;
    wypisz(wynik);
}

void div(wymierna liczba1, wymierna liczba2){
    wymierna wynik;
    wynik.liczebnik = liczba1.liczebnik * liczba2.mianownik;
    wynik.mianownik = liczba1.mianownik * liczba2.liczebnik;
    wypisz(wynik);
}

int main(){
    wymierna liczba1;
    wymierna liczba2;
    liczba1.liczebnik = 1;
    liczba1.mianownik = 2;
    liczba2.liczebnik = 4;
    liczba2.mianownik = 5;
    wypisz(liczba1);
    wypisz(liczba2);
    printf("Suma:  ");
    sum(liczba1, liczba2);
    printf("Różnica:  ");
    sub(liczba1, liczba2);
    printf("Iloczyn:  ");
    mul(liczba1, liczba2);
    printf("Iloraz:  ");
    div(liczba1, liczba2);
    return 0;
}