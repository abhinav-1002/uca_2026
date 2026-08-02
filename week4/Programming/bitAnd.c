#include <stdio.h>

int bitAnd(int a, int b){
    return ~(~a | ~b);
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);

    int ans=bitAnd(a, b);

    printf("%d", ans);
    return 0;
}
