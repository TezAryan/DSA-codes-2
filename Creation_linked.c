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

    createElement(&head);
    printNode(head);

    // Free the allocated memory (not shown in your code but important in practice)
    // struct node *temp;
    // while (head != NULL) {
    //     temp = head;
    //     head = head->next;
    //     free(temp);
    // }

    return 0;
}




//////////////////////  Psudo code  ////////////////////////
/*

Define Node Structure:
    Node:
        data
        next

Initialize head to NULL

Function CreateElement(head):
    choice = 1
    while choice == 1:
        newnode = Create a new Node
        if newnode is NULL:
            Print "Memory allocation failed."
            Exit function

        Print "Enter data: "
        Read newnode.data
        newnode.next = NULL

        if head is NULL:
            head = newnode
        else:
            temp = head
            while temp.next is not NULL:
                temp = temp.next
            temp.next = newnode

        Print "For continue 1 or 0: "
        Read choice

*/






//////////////////////////////  Algorithem ///////////////////
/*


Algorithm for Creating a Singly Linked List = 

1. Define the Node Structure:
Define Node:
    - data: to store the value of the node
    - next: pointer to the next node in the list

2. Initialize the List:
Initialize head to NULL

3. Function to Create and Insert Elements:

Function CreateElement(head):
    choice = 1
    while choice == 1:
        // Step 1: Allocate memory for a new node
        newnode = Allocate memory for a Node
        
        // Step 2: Check if memory allocation was successful
        if newnode is NULL:
            Print "Memory allocation failed."
            Exit function
        
        // Step 3: Input data for the new node
        Print "Enter data: "
        Read newnode.data
        newnode.next = NULL
        
        // Step 4: Insert the new node into the list
        if head is NULL:
            // If the list is empty, make the new node the head
            head = newnode
        else:
            // Traverse to the end of the list
            temp = head
            while temp.next is not NULL:
                temp = temp.next
            
            // Append the new node to the end of the list
            temp.next = newnode
        
        // Step 5: Ask if the user wants to add more nodes
        Print "For continue 1 or 0: "
        Read choice

4. End of Algorithm


*/


