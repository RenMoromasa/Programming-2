#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node, *nodePTR;

int createNode(Node* );
void insertFront(nodePTR* , int );
void insertLast(nodePTR* , int );
void insertAtPos(nodePTR* , int , int );
void DeleteFront(nodePTR* );
void DeleteLast(nodePTR* );
void DeleteAtPos(nodePTR* , int,  int );
void Display(nodePTR );

int main(){

    nodePTR head = NULL;

    printf("Insert at Front: \n");
    insertFront(&head, 10);
    insertFront(&head, 20);

    printf("Insert at End: \n");
    insertLast(&head, 30);
    insertLast(&head, 40);

    printf("Insert at Position 2: \n");
    insertAtPos(&head, 2, 50);
    insertAtPos(&head, 3, 60);


    return 0;
}

int createNode(Node* head){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = head;
    newNode->next = NULL;
    return newNode;
}

void insertFront(nodePTR *head, int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertLast(nodePTR *head, int data){
    Node* newNode = createNode(data);

    while(*head != NULL){
        head = &(*head)->next;
    }
    *head = newNode;
}

void insertAtPos(nodePTR* head, int pos, int data){
    nodePTR newNode = createNode(data);
    int count;
    nodePTR *current = head;

    newNode->data = data;
    
    for(count = 0; *current != NULL && count < pos; count++){
        current = &(*current)->next;
    }

    newNode->next = *current;
    *current = newNode;
}

void deleteFront(nodePTR* head){
    nodePTR temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteLast(nodePTR* head){

    nodePTR temp = *head;
    nodePTR prev;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void DeleteAtPos(nodePTR* head, int pos, int data){
    nodePTR temp = *head;
    nodePTR prev;
    int count;

    for(count = 0; temp->next != NULL && count < pos; count++){
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

void Display(nodePTR head){
    while(head != NULL){
        printf("%d ", head->data);
    }
    printf("\n");
}