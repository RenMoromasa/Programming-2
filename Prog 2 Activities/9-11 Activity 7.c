#include <stdio.h>
#include <string.h>

int insertfirst (int arr[], int *size, int element); 
int insertlast (int arr[], int *size, int element); 
int deletefirst (int arr[], int *size);
int deletelast (int arr[], int *size); 

int main () {
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Insert first: ");
    insertfirst(arr, &size, 0);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertlast(arr, &size, 6);
    printf("After inserting 6 at the end: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    deletefirst(arr, &size);
    printf("After deleting the first element: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    deletelast(arr, &size);
    printf("After deleting the last element: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


int insertfirst (int arr[], int *size, int element){

    for(int i = *size; i > 0; i--){
        arr[i] = arr[i-1];
    }

    arr[0] = element;
    (*size)++;

    return 1;
    
}

int insertlast (int arr[], int *size, int element){

    arr[(*size)++] = element;
    return 1;

}

int deletefirst (int arr[], int *size){

    for(int i = 0; i < *size - 1; i++){
        arr[i] = arr[i+1];
    }

    (*size)--;

    return 1;
}

int deletelast (int arr[], int *size){

    (*size)--;

    return 1;
}