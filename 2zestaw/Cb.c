#include <stdio.h>

int main(){
    int iloscSegmentow;
    int obecnySegment=0;
    int obecnyPoziom=0;

    printf("Podaj ilosc segmentow: \n");
    scanf("%d", &iloscSegmentow);
    for (obecnySegment = 0; obecnySegment < iloscSegmentow; ++obecnySegment){
        for (obecnyPoziom = 1; obecnyPoziom < obecnySegment+3; obecnyPoziom = obecnyPoziom + 1){
            for (int i=0; i < iloscSegmentow-obecnyPoziom+1; i++){ printf(" ");}
            for (int i=0; i < obecnyPoziom * 2 - 1 ; i = i + 1){
                printf("*");
            }
            printf("\n");
        }
    }
}