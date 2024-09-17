/*
2024-09-17-20-53-26.png
*/
#include <stdio.h>
#include <stdlib.h>

int *transferInRange(int arr[], int n, int low, int high, int *rangeCount);

int main() {
    int arr[] = {1, 15, 25, 30, 50, 65, 70, 80};
    int n = 8;
    int low, high;
    int rangeCount = 0;
    
    printf("Input Low Range: ");
    scanf("%d", &low);
    printf("Input High Range: ");
    scanf("%d", &high);
    
    int *result = transferInRange(arr,n,low,high, &rangeCount);
    
    if(rangeCount == 0){
        printf("No elements in range [%d,%d]", low, high);
    } else {
        printf("Elements in range [%d, %d]: ", low, high);
        for(int i = 0; i < rangeCount; i++){
            printf("%d ", result[i]);
        }
    }
}

int *transferInRange(int arr[], int n, int low, int high, int *rangeCount){
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= low && arr[i] <= high){
            count++;
        }
    }
    
    int *rangeArr = (int *)malloc(sizeof(int) * count);
    
    int index = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= low && arr[i] <= high){
            rangeArr[index++] = arr[i];
        }
    }
        *rangeCount = count;
        
        return rangeArr;
}