#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <conio.h>
#define ROZMIAR 30

struct probka{
    char nazwa[100];
    unsigned long id;
    double wartosc;
};

struct probka tablica[ROZMIAR];


int wypelnij(const char *nazwaPliku){
  const int max_n= 80;
  char napis[max_n], *result;
  char * pch;
  struct probka *p = tablica;
  FILE * fp;
  fp = fopen(nazwaPliku, "r");
//  long id_ = 1;
  while (result != NULL){
    result = fgets (napis, max_n, fp);   // czytamy ze standardowego wejścia
    if (result != NULL && strlen(result) > 5){
      napis[strlen(result)-1]='\0';

      pch = strtok (napis,";");
      strcpy(p->nazwa, pch);
      pch = strtok (NULL, ";");
      pch = strtok (NULL, ";");
      pch = strtok (NULL, ";");
      p->wartosc = atof(pch);

      p++;

    }
  }

  return 0;
}


int partition(int a, int b){
  double tmp, e;
  e=tablica[a].wartosc; 
//  printf("%f\n", e);
  while (a<b){
    while ((a < b) && (tablica[b].wartosc >= e)) b--;
    while ((a < b) && (tablica[a].wartosc < e)) a++;
    if (a < b){
      tmp = tablica[a].wartosc;
      tablica[a].wartosc = tablica[b].wartosc;
      tablica[b].wartosc = tmp;
    }
  }
  return a;
}

int algorytmHoare(){
  int n, w, i, j, k;
  n=ROZMIAR;
  w=ROZMIAR/2;
  i=0;
  j=n-1;

  n = w;
  while (i!=j){
    k=partition(i,j);
    k=k-i+1;
    if (k>=w) j=i+k-1;
    if (k<w){
      w-=k;
      i+=k;
    }
  }
  printf("mediana wynosi %f", tablica[i].wartosc);
}

int main ()
{
  int i;
  wypelnij("lista.txt");
  algorytmHoare();

  for(i =0; i<sizeof(tablica) / sizeof(struct probka); i++){
//    printf("%s, ", tablica[i].nazwa);
//    printf("%d, %f \n", tablica[i].id, tablica[i].wartosc);
  }

}
