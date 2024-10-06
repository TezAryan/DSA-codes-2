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

// Function to delete the last node of the singly linked list
void DeleteLast(struct node **head) {
    struct node *temp, *prev;

    if (*head == NULL) {
        printf("List is empty. No nodes to delete.\n");
        return;
    }

    // If there's only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    temp = *head;
    // Traverse to the second-to-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // temp is now the second-to-last node
    prev = temp;
    temp = temp->next;  // Last node

    prev->next = NULL;  // Remove the reference to the last node
    free(temp);          // Free the last node

    printf("Last node deleted.\n");
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
        int ch;
        printf("1 for Create Element:\n2 for Delete Last Element:\n3 for Print Node Element:\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                createElement(&head);
                break;
            case 2:
                DeleteLast(&head);
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
