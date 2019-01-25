#include <stdio.h>
#include <stdlib.h>
#define ZA_MALO_PAMIECI -1

typedef struct wezel {
    int wartosc;
    struct wezel *lewy, *prawy;

} Wezel;
Wezel *korzen = NULL;

Wezel *nowyWezel(int liczba){
  Wezel *nowy; 
  
  if( (nowy = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }
  nowy->wartosc = liczba;
  nowy->lewy = NULL;
  nowy->prawy = NULL;

  return nowy;
}


Wezel *wstaw(Wezel *wezelek, int liczba){
    
  if (wezelek==NULL){
      wezelek = nowyWezel(liczba);
  }
  else{
      if (wezelek->wartosc > liczba){
          wezelek->lewy = wstaw(wezelek->lewy, liczba);
      }
      else{
          wezelek->prawy = wstaw(wezelek->prawy, liczba);
      }
  }
  return wezelek;
}
void wstaw_inaczej(/*parametry*/){//2pkt
  /*Zmodyfikuj funkcje wstaw w taki sposób,
  by nie musiała zwracac elementu typu Wezel*/
}


void preorder(Wezel *wezelek){
		/*wypisz preorder (wezelek, lewe, prawe)*/
  printf("%d\n", wezelek->wartosc);
  if (wezelek->lewy !=NULL)
     preorder(wezelek->lewy);

  if (wezelek->prawy !=NULL)
     preorder(wezelek->prawy);
}


void inorder(Wezel *wezelek){//1pkt
		/*wypisz inorder (lewe, wezelek, prawe)*/
    if (wezelek->lewy != NULL){
        inorder(wezelek->lewy);
    }
    printf("%d\n", wezelek->wartosc);
    if (wezelek->prawy != NULL){
        inorder(wezelek->prawy);
    }
}


void postorder(Wezel *wezelek){//1pkt
		/*wypisz postorder (lewe, prawe, wezelek)*/
    if (wezelek->lewy != NULL){
        postorder(wezelek->lewy);
    }
    if (wezelek->prawy != NULL){
        postorder(wezelek->prawy);
    }
    printf("%d\n", wezelek->wartosc);
}


Wezel* szukaj(Wezel* wezelek, int liczba){//2pkt
		/*znajdz i zwroc element o podanym kluczu*/
    if(wezelek==NULL){
        return NULL;
    }
    else if(wezelek->wartosc == liczba){
        return wezelek;
    }
    else if(liczba < wezelek->wartosc){
        return szukaj(wezelek->lewy, liczba);
    }
    else if(liczba >= wezelek->wartosc){
        return szukaj(wezelek->prawy, liczba);
    }
}


int wysokosc(Wezel *wezelek) {//1pkt
		/*oblicz i zwroc wysokosc drzewa*/
    if(wezelek==NULL){
        return-1;
    }
    int l_wys = wysokosc(wezelek->lewy);
    int r_wys = wysokosc(wezelek->prawy);
    if(l_wys > r_wys){
        return l_wys +1;
    }
    else{
        return r_wys +1;
    }
}

Wezel* usun(Wezel* wezelek, int k) {//3pkt
    /*usuwanie elementu z drzewa
        1. w przypadku, gdy usuwany węzeł nie ma synów (jest liściem) 
           usunięcie przebiega bez reorganizacji drzewa – wskaźnik do 
           węzła w jego ojcu zastępowany jest wskaźnikiem do węzła pustego
        2. w przypadku, gdy usuwany węzeł ma jednego syna to dany węzeł usuwamy 
           a jego syna podstawiamy w miejsce usuniętego węzła
        3. w przypadku, gdy usuwany węzeł ma dwóch synów to po jego usunięciu 
           wstawiamy w jego miejsce węzeł, który jest jego następnikiem (który nie ma lewego syna)*/
 
    if (wezelek == NULL) 
        return wezelek; 
  
    if (wezelek->wartosc > k) { 
        wezelek->lewy = usun(wezelek->lewy, k); 
        return wezelek; 
    } 
    else if (wezelek->wartosc < k) { 
        wezelek->prawy = usun(wezelek->prawy, k); 
        return wezelek; 
    } 

    if (wezelek->lewy == NULL) { 
        Wezel* temp = wezelek->prawy; 
        wezelek = NULL; 
        return temp; 
    } 
    else if (wezelek->prawy == NULL) { 
        Wezel* temp = wezelek->lewy; 
        wezelek = NULL; 
        return temp; 
    } 
    else { 
        Wezel *nastepnik = wezelek->prawy; 
        while (nastepnik->lewy != NULL) { 
            nastepnik = nastepnik->lewy; 
        } 
  
        wezelek->wartosc = nastepnik->wartosc;
        wezelek->prawy = nastepnik->prawy; 
        nastepnik = NULL; 
        return wezelek; 
    } 
} 


int main() {
    Wezel *element = NULL;
    int i, liczba;


    
    int dane[] = {4, 7, 1, 0, 2, 3, 5, 8, 9, 6};
    
    for(i = 0; i <10; i++) {
        korzen = wstaw(korzen, dane[i]);
        //wstaw_inaczej(..............);
    }
    printf("Preorder:\n");
    preorder(korzen);
    printf("Inorder:\n");
    inorder(korzen);
    printf("Postorder:\n");
    postorder(korzen);
    printf("Jaki element chcesz znalezc? ");
    scanf("%d", &liczba);
    
    element = szukaj(korzen, liczba);
    if(element)
       printf("Znaleziono element, który zawiera wartosc %d\n", element->wartosc);
    else
       printf("Nie znaleziono elementu, który zawiera wartosc %d\n", liczba);
    
    printf("Wysokosc drzewa: %d\n", wysokosc(korzen));

    element = usun(korzen, 7);
    preorder(korzen);

    return 0;
}
