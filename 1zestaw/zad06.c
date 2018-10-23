#include <stdio.h>
#include <string.h>

int main(){
    char tekst[50];
    printf("Napisz dowolne zdanie uzywajac tabulatora\n");
    scanf("%[^\n]", tekst);
    for (int i = 0; i < strlen(tekst); i++){
        if ((int)tekst[i] == 9){
            printf("___");
        }
        else{ 
		printf("%c", tekst[i]);
	}
    }
    return 0;
}
