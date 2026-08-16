#include <stdio.h>

int findNum(int arr[], int n){
    int res=0;
    for (int i=0;i<32;i++){
        int cnt=0;

        for(int j=0;j<n;j++){
            if(arr[j] & (1<<i)){
                cnt++;
            }
        }

        if (cnt%3==1){
            res=res | (1<<i);
        }
    }

    return res;
}

int main(){
    int arr[] = {1,2,3,4,1,2,4,1,2,3,4,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d",findNum(arr, n));

    return 0;
}
