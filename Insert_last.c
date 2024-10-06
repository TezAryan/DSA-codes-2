#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create and insert elements into the singly linked list
void createElement(struct node **head) {
    int choice = 1;
    struct node *temp, *newnode;

    while (choice == 1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {  // Check for memory allocation failure
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (*head == NULL) {
            *head = newnode;  // If the list is empty, make the new node the head
        } else {
            temp = *head;
            // Traverse to the end of the list
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;  // Append the new node to the end of the list
        }

        printf("For continue 1 or 0: ");
        scanf("%d", &choice);
    }
}

// Function to insert a new node at the end of the singly linked list
void InsertatLast(struct node **head) {
    struct node *temp, *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;  // If the list is empty, make the new node the head
    } else {
        temp = *head;
        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;  // Append the new node to the end of the list
    }

    printf("\nNode inserted at the last\n");
}

// Function to print the elements of the singly linked list
void printNode(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");  // Print newline at the end of the list
}

int main() {
    struct node *head = NULL;
    int choice = 1;

    while (choice == 1) {
        int ch;
        printf("1 for Create Element:\n2 for Insert at Last:\n3 for Print Node Element:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createElement(&head);
                break;
            case 2:
                InsertatLast(&head);
                break;
            case 3:
                printNode(head);
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }

        printf("\nFor continue press 1 or any other key to exit: ");
        scanf("%d", &choice);
    }

    // Free the allocated memory
    struct node *temp;
    while (head != NULL) {
        temp = head; 
        head = head->next;
        free(temp);
    }

    return 0;
}
