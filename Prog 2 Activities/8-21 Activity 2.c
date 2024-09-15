#include <stdio.h>

int main(){
	
	int arr[100];
	int size, i;
	
	int evenArr[100];
	int evenCount = 0;
	
	int oddArr[100];
	int oddCount = 0;
	
	printf("Enter size: ");
	scanf("%d", &size);

	printf("Enter values: \n");
	
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("\nArray = [");
	for(i = 0; i < size; i++){
		if(arr[i] % 2 == 0){
			arr[i] *= 2;
			printf("%d", arr[i]);
		} else {
			arr[i] *= 3;
			printf("%d", arr[i]);
		}
		if(i != size - 1){
			printf(", ");
		}
	}	
	printf("]\n\n");
	
	// Activity 3
	printf("Enter size of second array: ");
	scanf("%d", &size);
	
	printf("Enter values: \n");
	
	for(i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	
	for(i = 0; i < size; i++){
		if(arr[i] % 2 == 0){
			evenArr[evenCount] = arr[i];
			evenCount += 1;	
		} else {
			oddArr[oddCount] = arr[i];
			oddCount += 1;
		}
	}
	
	printf("\nEven Array = ");
		for(i = 0; i < evenCount; i++){
			printf("%d", evenArr[i]);
		if(i != evenCount - 1){
			printf(", ");
			}
		}		
	
	printf("\nOdd Array = ");
		for(i = 0; i < oddCount; i++){
			printf("%d", oddArr[i]);
		if(i != oddCount - 1){
			printf(", ");
			}
		}	
	
	return 0;
	
}
