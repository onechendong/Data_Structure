#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

const long long int INF=0x3f3f3f3f3f;
int node=8, s;
int array[8][8];

void Folyd(){
    int max;
    for(int k=0;k<node;k++){
        for(int i=0;i<node;i++){
            for(int j=0;j<node;j++){

                if(array[i][k]>array[k][j]){
                    max=array[i][k];
                }
                else{
                    max=array[k][j];
                }
                
                if(array[i][j]>max){
                    array[i][j]=max;
                }

            }
        }
    }
}

int main(){
    //set up
    for(int i=0;i<node;i++){
        for(int j=0;j<node;j++){
            array[i][j]=INF;
            if(i==j){
                array[i][j]=0;
            }
        }
    }
    array[1][2] = 50; 
    array[2][1] = 50;
    array[1][3] = 60;
    array[3][1] = 60;
    array[2][4] = 120;
    array[4][2] = 120;
    array[2][5] = 90;
    array[5][2] = 90;
    array[3][6] = 50;
    array[6][3] = 50;
    array[4][6] = 80;
    array[6][4] = 80;
    array[4][7] = 70;
    array[7][4] = 70;
    array[5][7] = 40;
    array[7][5] = 40;
    array[6][7] = 140;
    array[7][6] = 140;
    Folyd();

    int times, node1, node2;
    scanf("%d", &times);
    int ans[times];
    for(int i=0;i<times;i++){
        scanf("%d %d", &node1, &node2);
        if(array[node1][node2]==INF){
            ans[i]=6666; //XDD
        }
        else{
            ans[i]=array[node1][node2];
        }
    }

    for(int i=0;i<times;i++){
        printf("%d\n", ans[i]);
    }

    return 0;

}