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

// Function to delete a node at a specific position
void DeleteAtPosition(struct node **head, int position) {
    struct node *temp = *head;
    struct node *prev = NULL;

    if (*head == NULL) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }

    // Traverse to the node before the one we want to delete
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // Node to be deleted is not the last node
    prev->next = temp->next;
    free(temp);  // Free memory of the deleted node

    printf("Node at position %d deleted.\n", position);
}

// Function to print the elements of the singly linked list
void printNode(struct node *head) {
    if (head == NULL) {
        printf("Null element\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");  // Indicate the end of the list
}

int main() {
    struct node *head = NULL;
    int choice = 1;

    while (choice == 1) {
        int ch, position;
        printf("1 for Create Element:\n2 for Delete at Specific Position:\n3 for Print Node Element:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createElement(&head);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                DeleteAtPosition(&head, position);
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

    return 0;
}
