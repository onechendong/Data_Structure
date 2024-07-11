#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(){
    int num;
    int ary[5][5];
    scanf("%d", &num);
    int ans[num];

    for(int i=0;i<num;i++){
        bool isup=true, isdown=1;
        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                scanf("%d", &ary[row][col]);
            }
        }

        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                if(col<row && ary[row][col]!=0){
                    isup=false;
                }
            }
        }
        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                if(col>=row && ary[row][col]==0){
                    isup=false;
                }
            }
        }

        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                if(col>row && ary[row][col]!=0){
                    isdown=false;
                }
            }
        }
        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                if(col<=row && ary[row][col]==0){
                    isdown=false;
                }
            }
        }

        if(isup){
            ans[i]=0;
        }
        else if(isdown){
            ans[i]=1;
        }
        else{
            ans[i]=-1;
        }
    }

    for(int i=0;i<num;i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}
//0:up 1:down -1:no