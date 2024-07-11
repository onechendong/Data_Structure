#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main(){
    int odd=0, even=0, times;
    scanf("%d", &times);
    int ans[times];
    char str[100000];
    for(int i=0;i<times;i++){
        odd=0, even=0;
        scanf("%s", str);
        int len=strlen(str), current=0;
        for(int j=0;j<len;j++){
            if(str[j]=='.'){
                current=current;
            }
            else if(current%2==0){
                odd+=str[j]-'0';
                current++;
            }
            else{
                even+=str[j]-'0';
                current++;
            }
            
        }

        if(abs(odd-even)==0||abs(odd-even)%11==0){
            ans[i]=1;
        }
        else{
            ans[i]=0;
        }
        

    }

    for(int i=0;i<times;i++){
        if(ans[i]==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}