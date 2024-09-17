#include <stdio.h>
#include <stdlib.h>

void getoddeven(int arr[], int size, int *evencount, int *oddcount, int **evenArr, int **oddArr);

int main (){

    int arr[100];
    int size;
    int evencount = 0, oddcount = 0;
    int *evenArr, *oddArr;

    printf("Enter size of array: ");
    scanf("%d", &size);

    printf("Enter values of array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    getoddeven(arr, size, &evencount, &oddcount, &evenArr, &oddArr);

    printf("Even Values: ");
    for(int i = 0; i < evencount; i++){
        printf("%d ", evenArr[i]);
    }

    printf("\nOdd Values: ");
    for(int i = 0; i < oddcount; i++){
        printf("%d ", oddArr[i]);
    }

    free(evenArr);
    free(oddArr);

}

void getoddeven(int arr[], int size, int *evencount, int *oddcount, int **evenArr, int **oddArr){

    int even = 0;
    int odd = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            even++;
        } else {
            odd++;
        }
    }

    *evenArr = (int *)malloc(sizeof(int) * even);
    *oddArr = (int *)malloc(sizeof(int) * odd);

    int evenindex = 0; 
    int oddindex = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            (*evenArr)[evenindex++] = arr[i];
        } else {
            (*oddArr)[oddindex++] = arr[i];
        }
    }

    *evencount = even;
    *oddcount = odd;

}
