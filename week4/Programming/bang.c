#include <stdio.h>

int bang(int a){
    return ((a | (~a + 1)) >> 31) + 1;
}

int main(){
    int a;
    scanf("%d", &a);

    int ans = bang(a);
    printf("%d", ans);
    
    return 0;
}
