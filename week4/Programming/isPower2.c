#include <stdio.h>

int isPower2(int x){

    if(x>0 && (x&(x-1)==0))
        return 1;
    else
        return 0;
}

int main(){
    int a;
    scanf("%d", &a);

    int ans = isPower2(a);
    printf("%d", ans);

    return 0;
}
