#include <stdio.h>
#include <stdlib.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
  int wartosc;
  struct wezel *nastepny;
  //struct wezel *poprzedni;//w przypadku listy dwukierunkowej
} Wezel;

Wezel *glowa = NULL;

/**********************************************************/

void wypisz() {
  Wezel *iterator = glowa;

  if(iterator == NULL){
    printf("Pusta lista\n");
  }

  while (iterator != NULL) {
    printf("%d\n", iterator->wartosc);
    iterator = iterator->nastepny;
  }
  printf("\n");
}

/**********************************************************/

void push_back(int liczba) {//wstaw element na koniec listy

  // konstruujemy nowy węzeł
  Wezel* element;
  Wezel* iterator = glowa;

  if( (element = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }
    element->wartosc = liczba;
    element->nastepny = NULL;

    if (iterator == NULL){//pusta lista
        glowa = element;
        return;
    }

    while (iterator->nastepny != NULL){
        iterator = iterator->nastepny;
    }

    iterator->nastepny = element;

}

/**********************************************************/

int pop_front() {//zwroc wartosc z poczatku listy i usun pierwszy element
int zwracana_wart = -1;
  Wezel *schowek = NULL;

  if (glowa == NULL) {
     return -1;
  }

  zwracana_wart = (glowa)->wartosc;
  schowek = (glowa);
  glowa = (glowa)->nastepny;
  free(schowek);
  return zwracana_wart;
}

/**********************************************************/

//2pkt
int remove_last(){//zroc wartosc z ostatniego elementu i usun ostatni element
  Wezel *iterator = glowa;
  int zwrac_wart = -1;
  if (glowa == NULL){
      return -1;
  }

    while (iterator->nastepny->nastepny!=NULL){
        iterator = iterator->nastepny;
    }
    printf("Ostatni element: %d\n", iterator->nastepny->wartosc);
    zwrac_wart = iterator->nastepny->wartosc;
    iterator->nastepny = NULL;
  return zwrac_wart;


}

/**********************************************************/
//2pkt
int remove_by_index(int indx){//zwroc wartosc elementu wskazywanego przez index i usun ten element
 int i = 0;
 int zwrac_wart = -1;
 Wezel *iterator = glowa;
 while (i < indx-1){
     i++;
     if (iterator->nastepny == NULL){
        fprintf(stderr, "Indeks poza zasięgiem listy!\n");
        exit(ZA_MALO_PAMIECI);
     }
     iterator = iterator->nastepny;
 }
 zwrac_wart = iterator->nastepny->wartosc;
 iterator->nastepny = iterator->nastepny->nastepny;
 printf("Wartosc elementu o indexie %d wynosi: %d\n", indx, zwrac_wart);
 return zwrac_wart;

}

/**********************************************************/
//2pkt
void push_front(int liczba) {//wstaw element na poczatek listy
Wezel *new_glowa;
Wezel *iterator = glowa;
new_glowa->wartosc = liczba;
new_glowa->nastepny = iterator;
glowa = new_glowa;
}


/**********************************************************/


int main(){

  push_back(3);
  printf("Po wstawieniu pierwszego elementu:\n");
  wypisz();

  push_back(5);
  push_back(8);
  push_back(20);
  push_back(12);
  push_back(1);
  printf("Po push_back z wartosciami: 5, 8, 20, 12, 1:\n");
  wypisz();
  
  pop_front();
  printf("Po pop_front:\n");
  wypisz();
  
  push_front(15);
  printf("Po push_front(15):\n");
  wypisz();
  
  remove_last();
  printf("Po remove_last:\n");
  wypisz();
  
  remove_by_index(1);
  printf("Po remove_by_index(1):\n");
  wypisz();



return 0;
}