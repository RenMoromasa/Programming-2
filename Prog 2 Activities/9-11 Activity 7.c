#include <stdio.h>
#include <string.h>

int insertfirst(int arr[], int size, int *count);
int insertlast (int arr[], int size, int *count);

int main (){

  int arr[5] = {1, 2, 3};
  int size = 5;
  int count = 3;

  insertfirst(arr, size, &count);
  insertlast (arr, size, &count);
  return 0;
}

int insertfirst (int arr[], int size, int *count){
  int i;

  memcpy(&arr[1],&arr[0],sizeof(int) * size);
  arr[0] = 10;
  (*count)++;

  printf("\nInsert first: ");
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }

  return 0;

}

int insertlast (int arr[], int size, int *count){
  int i;

  for(i = 0; i < (*count); i++){}
    arr[i] = 9;
    (*count)++;

  printf("\nInsert last: ");
  for(i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

