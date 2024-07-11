#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    int arr[M][N];
    for(int row=0;row<M;row++){
        for(int col=0;col<N;col++){
            scanf("%d", &arr[row][col]);
        }
    }

    int m=N;
    int n=M;
    int new_arr[m][n];
    for(int ROW=0, col=0;ROW<M, col<n;ROW++, col++){
        for(int COL=0, row=0;COL<N, row<m;COL++, row++){
            new_arr[row][col]=arr[ROW][COL];
        }
    }

    for(int row=0;row<m;row++){
        for(int col=0;col<n;col++){
            printf("%d ", new_arr[row][col]);
        }
        printf("\n");
    }

    return 0;
}