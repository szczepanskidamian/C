#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 24


struct obiekt{
    float wartosc;
    char nazwa[16];
};

struct obiekt spis[ROZMIAR];

int wypelnij(){
  const int max_n= 80;
  char napis[max_n], *result;
  char * pch;
  struct obiekt *p = spis;
  FILE * fp;
  fp = fopen("lista.txt", "r");
  while (result != NULL)
  {
    result = fgets (napis, max_n, fp);  
    if (result != NULL && strlen(result) > 5){
      napis[strlen(result)-1]='\0';
      pch = strtok (napis,";");
      pch = strtok (NULL, ";");
      strcpy(p->nazwa, pch);

      pch = strtok (NULL, ";");
      pch = strtok (NULL, ";");
      p->wartosc = atof(pch);
      p++;

    }
  }
  return 0;
}


int compare(const void *o1, const void *o2)
{
  struct obiekt *p1 = (struct obiekt *)o1;
  struct obiekt *p2 = (struct obiekt *)o2;
  return (int)(100.f*p1->wartosc - 100.f*p2->wartosc);
}

int main (){
  wypelnij();
  qsort(spis, ROZMIAR, sizeof(struct obiekt), &compare);
  int i;
  for(i =0; i<sizeof(spis) / sizeof(struct obiekt); i++){
    printf("%s, %f \n", spis[i].nazwa, spis[i].wartosc);
  }

}
