#include <stdio.h>

void setZeroes(int matrix[3][4],int m,int n){
    int col0=1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                // ith row
                matrix[i][0]=0;

                // jth col
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j]!=0){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    if(matrix[0][0]==0){
        for(int j=0;j<n;j++){
            matrix[0][j]=0;
        }
    }

    if(col0==0){
        for(int i=0;i<m;i++){
            matrix[i][0]=0;
        }
    }
}

int main() {
    int matrix[3][4]={
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    int m=3;
    int n=4;

    setZeroes(matrix,m,n);

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
