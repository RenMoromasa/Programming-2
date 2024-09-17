/*
2024-09-17-20-51-03.png
*/
#include <stdio.h>
#include <stdlib.h>


int* transferOddIndexed(int* arr, int n, int* oddCount);

int main() {
    int arr[] = {10, 21, 32, 43, 54, 65, 76};
    int n = 7;
    int oddCount = 0;
    
    int *result = transferOddIndexed(arr, n, &oddCount);
    
    printf("Odd-indexed elements: ");
    for(int i = 0; i < oddCount; i++){
        printf("%d ", result[i]);
    }
}

int* transferOddIndexed(int* arr, int n, int* oddCount){
    int count = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0){
            count++;
        }
    }
    
    int *oddArr = (int *)malloc(sizeof(int) * count);
    
    int oddindex = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0){
            oddArr[oddindex++] = arr[i];
        }
    }
    
    *oddCount = count;
    
    return oddArr;
}