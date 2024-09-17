/*
2024-09-17-20-52-23.png
*/

#include <stdio.h>
#include <stdlib.h>

int transferPosNeg(int arr[], int n, int *posCount, int *negCount, int **posArr, int **negArr);

int main() {
    int arr[] = {-5, 10, -20, 15, -30, 25, 40};
    int n = 7;
    int posCount, negCount;
    int *posArr, *negArr;
    transferPosNeg(arr,n, &posCount, &negCount, &posArr, &negArr);
    
    printf("Positive numbers: ");
        for(int i = 0; i < posCount; i++){
            printf("%d ", posArr[i]);
        }
    printf("\nNegative numbers: ");
        for(int i = 0; i < negCount; i++){
            printf("%d ", negArr[i]);
        }
}

int transferPosNeg(int arr[], int n, int *posCount, int *negCount, int **posArr, int **negArr){
    
    int positive = 0;
    int negative = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            positive++;
        } else if (arr[i] < 0){
            negative++;
        }
    }
    
    *negArr = (int *)malloc(sizeof(int) * negative);
    *posArr = (int *)malloc(sizeof(int) * positive);
    
    int indexneg = 0, indexpos = 0;
        for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            (*posArr)[indexpos++] = arr[i];
        } else if (arr[i] < 0){
            (*negArr)[indexneg++] = arr[i];
        }
    }
    
    *posCount = positive;
    *negCount = negative;
    
}