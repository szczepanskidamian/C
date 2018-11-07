#include <stdio.h>
#include <math.h>

unsigned doPot2(unsigned x);

int main(){
    printf("Najmniejsza potega 2 wieksza od %d to: %0.0f\n", 0, pow(2,doPot2(0)));
    printf("Najmniejsza potega 2 wieksza od %d to: %0.0f\n", 1000, pow(2,doPot2(1000)));
    return 0;
}

unsigned doPot2(unsigned x){
    unsigned i = 1;
    int potega = 0;
    while (i < x){
        i = i * 2;
        potega ++;
    }
    return potega;
}
