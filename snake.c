#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#define ZA_MALO_PAMIECI -1
#define ROZMIAR 20

typedef struct wezel {
  int x;
  int y;
  struct wezel *nastepny;
  struct wezel *poprzedni;
} Wezel;

Wezel *glowa = NULL;
Wezel *ogon = NULL;
int x=0, y=1;

void wypisz() {
  Wezel *iterator = ogon;

  if(iterator == NULL){
    printf("Pusta lista\n");
  }
  while (iterator != glowa) {
    mvaddstr(iterator->x, iterator->y,"o");
    iterator = iterator->poprzedni;
  }
  mvaddstr(iterator->x, iterator->y,"@");
}

void go_to(int x, int y){
  Wezel *iterator = ogon;
  while(iterator!=glowa){
    iterator->x = iterator->poprzedni->x;
    iterator->y = iterator->poprzedni->y;
    iterator = iterator->poprzedni;
  }
  glowa->x += x;
  glowa->y += y;
}

void push_back(int x, int y) {
  Wezel* element;
  Wezel* iterator = glowa;

  if( (element = (Wezel*)malloc(sizeof(Wezel))) == NULL ) {
    fprintf(stderr, "Za mało pamięci!\n");
    exit(ZA_MALO_PAMIECI);
  }
    element->x = x;
    element->y = y;
    element->nastepny = NULL;
    element->poprzedni = NULL;

    if (iterator == NULL){
        glowa = element;
        ogon = element;
        return;
    }

    while (iterator->nastepny != NULL){
        iterator = iterator->nastepny;
    }

    iterator->nastepny = element;
    element->poprzedni = iterator;
    ogon = element;
}

bool kolizja(){
  Wezel *iterator = glowa->nastepny;
  while(iterator!=NULL){
    if (iterator->x==glowa->x && iterator->y==glowa->y){ 
      return true;
    }
    iterator = iterator->nastepny;
  }
  return false;
}

bool inSnake(int x, int y){
  Wezel *iterator = glowa;
  while(iterator!=NULL){
    if(x==iterator->x && y == iterator->y){
      return true;
    }
    iterator = iterator->nastepny;
  }
  return false;
}

void restart(){
  x=0;
  y=1;
  glowa = NULL;
  ogon = NULL;
  setup();
}

void setup(){
  push_back(ROZMIAR/2,ROZMIAR/2);
  push_back(ROZMIAR/2,ROZMIAR/2-1);
  push_back(ROZMIAR/2,ROZMIAR/2-2);
}

void genFood(){
  
}

//Proszę dokonczyc gre.
//compilacja: gcc snake.c -lncurses
int main(void) 
{
  WINDOW * mainwin;
  setup();

  // Initializacja ncurses
  if ( (mainwin = initscr()) == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }
  noecho();         // nie pokazuj wpisywanych danych
  cbreak();         // disables line buffering and erase/kill character-processing
  timeout(500);     // wait 500ms for key press

  time_t t;
  srand((unsigned) time(&t));

  // Tak można dac X we wskazanym miejscu lub uzyc mvaddstr jak nizej
  // move(15,10); 
  // addch('X');

  int owoc_x = rand() % ROZMIAR-2;
  int owoc_y = rand() % ROZMIAR-2;
  int points = 0;
  int hscore = 0;
  char tekst[6];

  bool quit = false;
  bool pause = false;
  // quit = kolizja();
  do {
    if (owoc_x<1){
      owoc_x=1;
    }
    else if(owoc_x>ROZMIAR-1){
      owoc_x=ROZMIAR-1;
    }
    if(owoc_y<1){
      owoc_y=1;
    }
    else if(owoc_y>ROZMIAR-1){
      owoc_y=ROZMIAR-1;
    }
    int c = getch();
    switch (c) 
    {
      case 'w':
      if(x==0){
        x = -1;
        y = 0;
      }
        break;
      case 's':
       if(x==0){
       x = 1;
        y = 0;
       }
        break;
      case 'a':
      if(y==0){
        x = 0;
        y = -1;
      }
        break;
      case 'd':
      if(y==0){
        x = 0;
        y = 1;
      }
        break;
      case 'q':
        quit = true;
        break;
      case ' ':
        pause = !pause;
        break;
    }
    clear();
    mvaddstr(owoc_x, owoc_y, "%");
    if (inSnake(owoc_x, owoc_y)==true){
      if(glowa->x==owoc_x && glowa->y == owoc_y){
        push_back(ogon->x, ogon->y);
        points += 10;
        if (points > hscore) hscore += 10;
      }
      owoc_x = rand() % ROZMIAR-2;
      owoc_y = rand() % ROZMIAR-2;
    }

    for (int x=0; x<=ROZMIAR; x++){
      mvaddstr(x, 0,"#");
      mvaddstr(x, ROZMIAR, "#");
    }
    for (int y=0; y<=ROZMIAR; y++){
      mvaddstr(0, y, "#");
      mvaddstr(ROZMIAR, y, "#");
    } 
    sprintf(tekst, "Points: %d", points);
    mvaddstr(ROZMIAR+2, 2, tekst);  
    sprintf(tekst, "Highscore: %d", hscore);
    mvaddstr(ROZMIAR+3, 2, tekst);  
    mvaddstr(ROZMIAR+5, 2, "Move: W, S, D, A");  
    mvaddstr(ROZMIAR+6, 2, "Pause: SPACEBAR");  
    mvaddstr(ROZMIAR+7, 2, "QUIT: Q");  
    if (!pause){
      go_to(x, y);
    }
    wypisz();
    refresh();
    if (glowa->y==ROZMIAR || glowa->y==0 || glowa->x==ROZMIAR || glowa->x==0 || kolizja()){
      restart();
      points = 0;
    }

  } while( ! quit );


  // Czyszczenie
  nocbreak();
  echo();
  refresh();
  delwin(mainwin);
  endwin();
  return EXIT_SUCCESS;
}