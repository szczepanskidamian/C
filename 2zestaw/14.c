#include <stdio.h>
#include <stdarg.h>

int max(int n, ...){
    int max;
    int i;
    va_list vl;
    va_start(vl,n);
    max = va_arg(vl, int);
    for(i =0; i<n; i++){
        int tmp = va_arg(vl, int);
        if (tmp > max){
            max = tmp;
        }
    }
    va_end(vl);
    return max;
}

int main()
{
    printf("{1,4,6,8,90,2,4,2,1,4,5,101,100}\nMax: %d\n", max(13, 103,4,6,8,90,2,4,2,1,4,5,101,102));
    return 0;
}
