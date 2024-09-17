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
    display(arr, &size);

    printf("Insert first: ");
    insertfirst(arr, &size, 0);
    display(arr, &size);

    insertlast(arr, &size, 6);
    printf("Insert last: ");
    display(arr, &size);

    deletefirst(arr, &size);
    printf("Delete first: ");
    display(arr, &size);

    deletelast(arr, &size);
    printf("Delete last: ");
    display(arr, &size);

    return 0;
}

int insertfirst (int arr[], int *size, int element){

    for(int i = *size; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = element;
    (*size)++;
    return 0;
    
}

int insertlast (int arr[], int *size, int element){

    arr[(*size)++] = element;
    return 0;

}

int deletefirst (int arr[], int *size){

    for(int i = 0; i < *size - 1; i++){
        arr[i] = arr[i+1];
    }
    (*size)--;
    return 0;

}

int deletelast (int arr[], int *size){

    (*size)--;
    return 0;
}

void display(int arr[], int *size) {

    for (int i = 0; i < *size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
