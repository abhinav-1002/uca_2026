#include <stdio.h>

void setZeroes(int matrix[3][4],int m,int n){
    int row[m];
    int col[n];

    for(int i=0;i<m;i++){
        row[i]=0;
    }

    for(int j=0;j<n;j++){
        col[j]=0;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }
}

int main(){
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
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
