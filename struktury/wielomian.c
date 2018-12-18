#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 10

typedef struct {
    int liczby[ROZMIAR];
}wielomian;


void wypisz(wielomian w){
  int i;
  for(i=ROZMIAR-1; i>=0; i--){
    if(w.liczby[i] != 0){
      printf("%dx^%d + ", w.liczby[i], i);
    }
  }
}


int main (){
  wielomian w;
  w.liczby[0] = 1;
  w.liczby[1] = 2;
  w.liczby[2] = 4;
  w.liczby[4] = 8;

  wypisz(w);
}