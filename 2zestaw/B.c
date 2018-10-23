#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int func(int x, int a, int b, int c);

int main(){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int a;
    int b;
    int c;
    int y;
    printf("Podaj a:\n");
    scanf("%d", &a);
    printf("Podaj b:\n");
    scanf("%d", &b);
    printf("Podaj c:\n");
    scanf("%d", &c);
    printf("%d\n", w.ws_col);
    for (int i=-8; i<=8; i++){
        y=func(i,a,b,c);
        for (int j=-(w.ws_col/2); j <= (w.ws_col/2); j++){
            if (j == y){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}


int func(int x, int a, int b, int c){
    return a * x * x + b * x + c;
}
