#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(){
    int card[17];
    int all[4][9]={0};
    int pair=0, face=0;

    for(int i=0;i<17;i++){
        scanf("%d", &card[i]);
    }
    
    for(int i=0;i<17;i++){
        if(card[i]>=0&&card[i]<=8){
            all[0][card[i]]++;
        }
        else if (card[i]>=9&&card[i]<=17){
            all[1][card[i]-9]++;
        }
        else if(card[i]>=18&&card[i]<=26){
            all[2][card[i]-18]++;
        }
        else{
            all[3][card[i]-27]++;
        }
    }

    /*for(int i=0;i<4;i++){
        for(int j=0;j<9;j++){
            printf("%d ", all[i][j]);
        }
        printf("\n");
    }*/

    for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            if(j+2<=8&&all[i][j]!=0&&all[i][j+1]!=0&&all[i][j+2]!=0){
                face++;
                all[i][j]--;
                all[i][j+1]--;
                all[i][j+2]--;
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            if(all[i][j]>3||all[i][j]==3){
                face++;
                all[i][j]-=3;
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<9;j++){
            if(all[i][j]==2){
                pair++;
            }
        }
    }
    for(int i=0;i<7;i++){
        if(all[3][i]>3||all[3][i]==3){
            face++;
            all[3][i]-=3;
        }
        if(all[3][i]==2){
            pair++;
            all[3][i]-=2;
        }
    }

    /*for(int i=0;i<4;i++){
        for(int j=0;j<9;j++){
            printf("%d ", all[i][j]);
        }
        printf("\n");
    }
    printf("%d %d", face, pair);*/

    if(face==5&&pair==1){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
    
    return 0;
}