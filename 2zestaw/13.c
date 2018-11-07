#include <stdio.h>

int przesuniecia(int liczba);
int main(){
    int x;
    while (1){
        scanf("%d", &x);
        printf("%d\n", przesuniecia(x));
    }
    return 0;
}

int przesuniecia(int liczba){
    if (liczba  == 0){
        return 0;
    }
    liczba = liczba>>1;
    while (liczba % 2 == 0){
        liczba = liczba >> 1;
    }
    return liczba;
}
