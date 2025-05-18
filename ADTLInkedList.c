#include <stdio.h>
#include <stdlib.h>

// Define Node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define List
typedef struct List {
    Node* head;
    int size;
} List;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}

// Initialize an empty list
void initializeList(List* list) {
    list->head = NULL;
    list->size = 0;
}

// Insert at beginning
Node* insertAtBeginning(List* list, int value) {
    Node* newNode = createNode(value);
    if(newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
    printf("Node %d inserted at Beginning\n", newNode->data);
    return newNode;
}

// Insert at end
Node* insertAtEnd(List* list, int value) {
    Node* newNode = createNode(value);
    if(newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }

    if(list->head == NULL) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
    printf("Node %d inserted at End\n", newNode->data);
    return newNode;
}

// Insert at specific position
Node* insertPosition(List* list, int value, int position) {
    if(position < 0 || position > list->size) {
        printf("Invalid position!\n");
        return NULL;
    }
    if(position == 0) {
        return insertAtBeginning(list, value);
    }

    Node* newNode = createNode(value);
    if(newNode == NULL) {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }

    Node* current = list->head;
    for(int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->size++;
    printf("Node %d inserted at position %d\n", newNode->data, position);
    return newNode;
}

// Delete from beginning
Node* deleteFromBeginning(List* list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    printf("Node %d deleted from beginning\n", temp->data);
    free(temp);
    list->size--;
    return NULL;
}

// Delete from end
Node* deleteFromEnd(List* list) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* current = list->head;
    Node* prev = NULL;

    while(current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if(prev == NULL) {
        list->head = NULL;
    } else {
        prev->next = NULL;
    }
    printf("Node %d deleted from end\n", current->data);
    free(current);
    list->size--;
    return NULL;
}

// Delete at specific position
Node* deletePosition(List* list, int position) {
    if(position < 0 || position >= list->size || list->head == NULL) {
        printf("Invalid position or empty list!\n");
        return NULL;
    }

    Node* temp;

    if(position == 0) {
        temp = list->head;
        list->head = list->head->next;
    } else {
        Node* current = list->head;
        for(int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
    }

    printf("Node %d deleted from position %d\n", temp->data, position);
    free(temp);
    list->size--;
    return NULL;
}

// Delete by value
Node* deleteByValue(List* list, int value) {
    if(list->head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }

    Node* temp = list->head;
    Node* prev = NULL;

    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return NULL;
    }

    if(prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Node %d deleted by value.\n", temp->data);
    free(temp);
    list->size--;
    return NULL;
}

// Search for a value
Node* search(List* list, int value) {
    Node* current = list->head;
    int position = 0;

    while(current != NULL) {
        if(current->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return current;
        }
        current = current->next;
        position++;
    }

    printf("Value %d not found in the list.\n", value);
    return NULL;
}

// Update a node's value
void updateNodeValue(List* list, int oldValue, int newValue) {
    Node* nodeToUpdate = search(list, oldValue);

    if(nodeToUpdate != NULL) {
        nodeToUpdate->data = newValue;
        printf("Node value updated from %d to %d.\n", oldValue, newValue);
    } else {
        printf("Value %d not found. Update failed.\n", oldValue);
    }
}

// Display the list
void displayList(List* list) {
    Node* current = list->head;
    printf("List: ");
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Count nodes
int countNodes(List* list) {
    return list->size;
}

// Check if the list is empty
int isEmpty(List* list) {
    return (list->head == NULL);
}

// Free the list
void freeList(List* list) {
    Node* current = list->head;
    Node* nextNode;

    while(current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    list->head = NULL;
    list->size = 0;
    printf("List freed successfully.\n");
}

// Main function with Menu
int main() {
    List list;
    initializeList(&list);
    int choice, value, position, oldValue, newValue;

    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Delete by Value\n");
        printf("8. Search for a Value\n");
        printf("9. Update a Node Value\n");
        printf("10. Display List\n");
        printf("11. Count Nodes\n");
        printf("12. Check if List is Empty\n");
        printf("13. Free List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&list, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&list, value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                insertPosition(&list, value, position);
                break;
            case 4:
                deleteFromBeginning(&list);
                break;
            case 5:
                deleteFromEnd(&list);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(&list, position);
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(&list, value);
                break;
            case 8:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(&list, value);
                break;
            case 9:
                printf("Enter old value and new value: ");
                scanf("%d %d", &oldValue, &newValue);
                updateNodeValue(&list, oldValue, newValue);
                break;
            case 10:
                displayList(&list);
                break;
            case 11:
                printf("Number of nodes: %d\n", countNodes(&list));
                break;
            case 12:
                if(isEmpty(&list))
                    printf("List is empty.\n");
                else
                    printf("List is not empty.\n");
                break;
            case 13:
                freeList(&list);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 0);

    return 0;
}
