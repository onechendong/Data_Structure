#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 合併函數，用於合併兩個子陣列
long long merge(char (*arr)[4], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // 左子陣列的大小
    int n2 = right - mid;     // 右子陣列的大小

    char L[n1][4], R[n2][4];  // 用於暫存左右子陣列的臨時陣列

    // 將數據複製到臨時陣列 L[] 和 R[] 中
    for (i = 0; i < n1; i++)
        strcpy(L[i], arr[left + i]);
    for (j = 0; j < n2; j++)
        strcpy(R[j], arr[mid + 1 + j]);

    i = 0;
    j = 0;
    k = left;
    long long count = 0;  // 變數用於計算交換次數

    // 合併臨時陣列回到 arr[left...right]
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            count += n1 - i;  // 計算交換次數
            j++;
        }
        k++;
    }

    // 複製 L[] 的剩餘元素（如果有的話）
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++;
        k++;
    }

    // 複製 R[] 的剩餘元素（如果有的話）
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++;
        k++;
    }

    return count;  // 返回總交換次數
}

// 合併排序函數
long long mergeSort(char (*arr)[4], int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;  // 找到中間點
        count += mergeSort(arr, left, mid);    // 遞歸地對左子陣列進行排序
        count += mergeSort(arr, mid + 1, right);  // 遞歸地對右子陣列進行排序
        count += merge(arr, left, mid, right);    // 合併已排序的子陣列
    }
    return count;  // 返回總交換次數
}

int main() {
    int num;
    scanf("%d", &num);
    char (*license)[4] = malloc(num * sizeof(char[4]));  // 分配存儲字串陣列的內存
    for (int i = 0; i < num; i++) {
        scanf("%3s", license[i]);  // 讀取輸入字串
    }

    long long ans = mergeSort(license, 0, num - 1);  // 執行合併排序並獲取總交換次數

    free(license);  // 釋放已分配的內存

    printf("%lld\n", ans);  // 印出總交換次數

    return 0;
}
