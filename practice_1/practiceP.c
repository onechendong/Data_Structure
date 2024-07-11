#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M); 
    int ans[M];

    for(int a=0;a<M;a++){
        int matrix[5][5];
        int isUpperTriangular = 1; 
        int isLowerTriangular = 1; 

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        for (int i = 1; i < 5; i++) {
            for (int j = 0; j < i; j++) {
                if (matrix[i][j] != 0) {
                    isUpperTriangular = 0; //非上
                    break;
                }
            }
        }

        
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (matrix[i][j] != 0) {
                    isLowerTriangular = 0; 
                    break;
                }
            }
        }

        
        if (isUpperTriangular) {
            ans[a]=0; // 上三角
        } else if (isLowerTriangular) {
            ans[a]=1; // 下三角
        } else {
            ans[a]=-1; // 不是上三角也不是下三角
        }
    }
    
    for(int tmp=0;tmp<M;tmp++){
        printf("%d\n", ans[tmp]);
    }

    return 0;
}
