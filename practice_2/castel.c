#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int bubbleSort(int arr[], int n){
    int count=0;
    int tmp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int times;
    scanf("%d", &times);
    int num=3; //how many char
    int array[num];
    int ans[times];
    for(int i=0;i<times;i++){
        for(int j=0;j<num;j++){
            scanf("%d", &array[j]);
        }
        ans[i]=bubbleSort(array, num);
    }

    //printf("\n");
    for(int i=0;i<times;i++){
        printf("%d\n", ans[i]);
    }
    
    return 0;
}