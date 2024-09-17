/*
024-09-17-20-48-26.png
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* transferPrimes(int* arr, int n, int* primeCount);

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = 10;
    int primeCount = 0;
    
    int *result = transferPrimes(arr, n, &primeCount);
    
    printf("Prime numbers: ");
    for(int i = 0; i < primeCount; i++){
        printf("%d ", result[i]);
    }
    
    return 0;
}

int isPrime(int num){
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    
    if (num % 2 == 0 || num % 3 == 0) return 0;
    
    for(int i = 5; i * i <= num; i+=6){
        if(num % i == 0 || num % (i + 2) == 0) return 0;
    }
    
    return 1;
    
}

int* transferPrimes(int* arr, int n, int* primeCount){
    int count = 0;
    
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            count++;
        }
    }
    
    int *primeArr = (int *)malloc(sizeof(int) * count);
    
    int primeIndex = 0;
    for(int i = 0; i < n; i++){
        if(isPrime(arr[i])){
            primeArr[primeIndex++] = arr[i];
        }
    }
    
    *primeCount = count;
    
    return primeArr;
}