#include <stdio.h>
#include <stdlib.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
    int wartosc;
    struct wezel *nastepny;
  //struct wezel *poprzedni;//w przypadku listy dwukierunkowej
} Wezel;

Wezel *glowa = NULL;
Wezel *element = NULL;
// int i=0;

/**********************************************************/

void wypisz() {
    int i = 0;
    Wezel *iterator = glowa;
    if(iterator == NULL){
    printf("Pusta lista\n");
    }

    if (iterator->nastepny == glowa){
        i++;
        printf("< %d >\n", iterator->wartosc);
        printf("Rozmiar listy cyklicznej: %d\n", i);
        return;
    }
        printf("< %d >\n", iterator->wartosc);
    while (iterator->nastepny != glowa) {
        iterator = iterator->nastepny;
        printf("< %d >\n", iterator->wartosc);
        i++;
    }
    i++;
    printf("Rozmiar listy cyklicznej: %d\n", i);
}

/**********************************************************/

void push_back(int liczba) {//wstaw element na koniec listy

  // konstruujemy nowy węzeł
    Wezel* nowy_element;
    Wezel* iterator = glowa;
    if( (nowy_element = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
        fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
    }    
    nowy_element->wartosc = liczba;
    nowy_element->nastepny = NULL;
    if (iterator == NULL){//pusta lista
        nowy_element->nastepny = nowy_element;
        glowa = nowy_element;
        element = nowy_element;
    }
    else {
        nowy_element->nastepny = element->nastepny;
        element->nastepny = nowy_element;
        glowa = nowy_element;
    }
}


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
return 0;
}