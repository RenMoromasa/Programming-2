#include <stdio.h>

void insertfirst(int arr[], int *size, int first);
void insertlast(int arr[], int *size, int last);
void display(int arr[], int size);

int main (){

    int arr[] = {1 , 2 , 3 , 4 ,5};
    int size = 5;
    int first, last;

    printf("Original Array: ");
    display(arr, size);

    printf("Enter number to insert first: ");
    scanf("%d", &first);

    insertfirst(arr, &size, first);
    display(arr, size);

    printf("Enter number to insert last: ");
    scanf("%d", &last);

    insertlast(arr, &size, last);
    display(arr, size);

    deletefirst(arr, &size);
    display(arr, size);
    deletelast(arr, &size);
    display(arr, size);
    
}

void display(int arr[], int size){
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertfirst(int arr[], int *size, int first){

    for(int i = *size; i > 0; i--){
        arr[i] = arr[i - 1];
    }
    
    arr[0] = first;
    (*size)++;

}

void insertlast(int arr[], int *size, int last){

    (arr[(*size)++]) = last;
    
}

void deletefirst (int arr[], int *size){
    for(int i = 0; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }

    (*size)--;

}

void deletelast (int arr[], int *size){

    (*size)--;

}
