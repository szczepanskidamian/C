#include <stdio.h>

int main(){
	char x;
	int count;
	int line = 1;
	while ((x = getchar())){
		count++;
		if (x == '\n' && count > 7){
			printf("%d\n", line);
			count = 0;
			line++;
		}
		else if (x == '\n'){
			count = 0;
			line++;
		}
	}
	return 0;
}
