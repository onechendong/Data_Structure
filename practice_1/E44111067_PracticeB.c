#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

int main(){
    int M;
    scanf("%d", &M);
    int ans[M];

    for(int i=0;i<M;i++){
        int N;
        scanf("%d", &N);
        int price[N];
        for(int j=0;j<N;j++){
            scanf("%d", &price[j]);
        }
        int max=0;
        for(int frount=0;frount<N-1;frount++){
            for(int back=frount+1;back<N;back++){
                if((price[back]-price[frount])>max){
                    max=price[back]-price[frount];
                }
            }
        }
        ans[i]=max;
    }

    for(int i=0;i<M;i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}
//easy game