#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create and insert elements into the circular linked list
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
            newnode->next = *head;  // Point the next of new node to itself
        } else {
            temp = *head;
            // Traverse to the end of the list
            while (temp->next != *head) {  // Check against head for circular nature
                temp = temp->next;
            }
            temp->next = newnode;  // Append the new node to the end of the list
            newnode->next = *head;  // Make it circular by pointing to head
        }

        printf("For continue 1 or 0: ");
        scanf("%d", &choice);
    }
}

// Function to print the elements of the circular linked list
void printNode(struct node *head) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != head) {  // Loop until the next node is the head
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    // Print the last node (which points back to the head)
    printf("%d\n", temp->data);
}


int main() {
    struct node *head = NULL;

    createElement(&head);
    printNode(head);

    // Free the allocated memory (not shown in your code but important in practice)
    // struct node *temp, *current;
    // current = head;
    // do {
    //     temp = current;
    //     current = current->next;
    //     free(temp);
    // } while (current != head);

    return 0;
}
