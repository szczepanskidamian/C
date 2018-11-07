#include <stdio.h>
int warunek(int x);
int funkcja(int x, int y);
int main(){
    // while
    int x;
    int y;
    for (x = 4; warunek(x)>0; x += funkcja(x,x+y)){
        printf("%d\n", x);
        y = 2 - x;
    }

    // do_while
    printf("\n\nDo while\n");
    x = 4;
     
    y = 2 -x;
    x += funkcja(x, x+y);
    printf("%d\n", x);
    for (int x; warunek(x)>0; x += funkcja(x,x+y)){
        printf("%d\n", x);
        y = 2 - x;
    }

    //if
    x = 4;
    for(int i = warunek(x); i > 0; i = 0){
        y = 2-x;
        x += funkcja(x, x+y);

    }
}
int warunek(int x){
    return x;
}

int funkcja(int x, int y){
    return -y;

}
