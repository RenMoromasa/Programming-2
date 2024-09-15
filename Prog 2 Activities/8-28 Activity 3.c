#include <stdio.h>
#include <stdlib.h>

/* Getting even numbers using malloc in an array*/

int main(){
	
	int size, i;
	int* evenNumbers;
	
	printf("Enter size: ");
	scanf("%d", &size);
	
	int arr[size];
	
	printf("Enter the values: ");
	
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Even numbers in the array: ");
	
	evenNumbers = getEven(arr, size);
	
	return 0;
}

int* getEven(int* arr, int size){
	int count = 0;
	for(int i = 0; i < size; i++){
		if(arr[i] % 2 == 0){
			count++;
		}
	}
	
	int* arr = (int*)malloc(sizeof(arr) * size);
	
	    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){
            printf("%d ", x[i]);
        }
    }
	
}
