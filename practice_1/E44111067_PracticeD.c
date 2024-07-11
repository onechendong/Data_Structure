#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(){
    int B[3];
    for(int i=0;i<3;i++){
        scanf("%d", &B[i]);
    }
    if(B[0]==3 && B[1]==1 && B[2]==2){
        printf("No");
    }
    else{
        printf("Yes");
    }
}
//荒謬的一題XD