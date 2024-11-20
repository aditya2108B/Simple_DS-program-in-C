/*	Write C program to Implementation following operations on singly linked list:
a.	Insert at beginning
b.	Insert at end
c.	Delete at beginning
d.	Delete at end
e.	Insert at nth position
f.	Delete at nth position
g.	Display
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void Search();
int element();
int position();
void Insert_at_begning(int element);
void insert_at_end(int element) ;
void Disply();
void insert_at_nth(int element, int position) ;
void Delete_from_nth_position(int position) ;
void Delete_from_end();
void Delete_from_beg() ;
// Main function 
void main() {
    int choice;
    do {
      printf("\n1.Insert at beginning\n2.Insert at end\n3.Delete at beginning\n4.Delete at end\n5.Insert at nth position\n6.Delete at nth position\n7.Display\n8.Search an Element in list\n9.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Insert_at_begning(element());
                break;
            case 2:
                insert_at_end(element());
                break;
            case 3:
              Delete_from_beg();
                break;
            case 4:
               Delete_from_end();
                break;
            case 5:
                insert_at_nth(element(), position());
                break;
            case 6:
               Delete_from_nth_position(position());
                break;
            case 7:
                  Disply();
                break;
            case 8:
                Search();
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 9);
}

// Function to prompt the user to enter an element
int element() {
    int ele;
    printf("Enter the Element to be inserted: ");
    scanf("%d", &ele);
    return ele;
}

// Function to prompt the user to enter a position
int position() {
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    return pos;
}

// Function to insert a new node at the beginning of the list
void Insert_at_begning(int element) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = head;
    head = temp;
}

// Function to display the linked list
void Disply() {
    if(head==NULL){
        printf("\n List is Empty");
    }else{
    printf("Linked list: ");
    struct Node *node = head;
    while (node != NULL) {
        printf("||%p|%d|%p|| --> ", node,node->data,node->next);
        node = node->next;
    }}
}

// Function to insert a new node at the end of the list
void insert_at_end(int element) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = temp;
    } else {
        struct Node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

// Function to insert a new node at a specified position in the list
void insert_at_nth(int element, int position) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;

    // Insert at the head if position is 1
    if (position == 1) {
        temp->next = head;
        head = temp;
    } else {
        struct Node *temp1 = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp1 == NULL) {
                printf("Position out of range\n");
                free(temp);
                return;
            }
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
    }
}

// Function to delete the node at the beginning of the list
void Delete_from_beg() {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp = head;
        head = temp->next;
        free(temp);
    }
}

// Function to delete the node at the end of the list
void Delete_from_end() {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp = head;
        struct Node *temp1 = NULL;
        while (temp->next != NULL) {
            temp1 = temp;
            temp = temp->next;
        }
        if (temp1 != NULL)
            temp1->next = NULL;
        else
            head = NULL;
        free(temp);
    }
}

// Function to delete a node at a specified position in the list
void Delete_from_nth_position(int position) {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp1 = head;

        // If deleting the head node
        if (position == 1) {
            head = head->next;
            free(temp1);
            return;
        }

        for (int i = 1; i < position - 1; i++) {
            if (temp1 == NULL) {
                printf("Position out of range\n");
                return;
            }
            temp1 = temp1->next;
        }

        struct Node *temp = temp1->next;
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
        temp1->next = temp->next;
        free(temp);
    }
}

// Function to search for an element in the list
void Search() {
    int element;
    printf("Enter the Element to be searched: ");
    scanf("%d", &element);

    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp = head;
        while (temp != NULL) {
            if (element == temp->data) {
                printf("Element Found\n");
                return;
            }
            temp = temp->next;
        }
        printf("Element Not Found\n");
    }
}

