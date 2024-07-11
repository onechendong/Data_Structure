#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int num;
    scanf("%d", &num);
    char str[100000];
    bool ans[num];

    for(int i=0;i<num;i++){
        int odd=0, even=0;
        scanf("%s", str);
        int L=strlen(str);

        for(int j=0;j<L;j+=2){
            even+=str[j]-'0';
        }
        for(int j=1;j<L;j+=2){
            odd+=str[j]-'0';
        }
        //printf("%d %d",even, odd);

        if((abs(even-odd))%11==0){
            ans[i]=true;
        }
        else{
            ans[i]=false;
        }
        
    }

    for(int i=0;i<num;i++){
        if(ans[i]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    
    return 0;
}
//是否為11倍數