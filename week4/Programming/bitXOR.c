#include <stdio.h>

int bitXOR(int a, int b){
    return ~(~(a & ~b) & ~(~a & b));
}

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = bitXOR(a, b);
    printf("%d", ans);
    
    return 0;
}
