 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
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
// Main function */
void main() {
    int choice;
    printf("Welcome to Doubly Link list ");
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

// Function to display the linked list
void Disply() {
    if(head==NULL){
        printf("\n List is Empty");
    }else{
    printf("Linked list: ");
    struct Node *node = head;
    while (node != NULL) {
        printf("|| previous Node=%u | data= %d |Next =%u| [temp=%u] || --> ", node->prev,node->data,node->next,node);
        node = node->next;
    }}
}
// Function to insert a new node at the beginning of the list
void Insert_at_begning(int element) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->prev=NULL;
    temp->data = element;
    if(head!=NULL){
        head->prev=temp;
    }
    temp->next = head;
    head = temp;
}


// Function to insert a new node at the end of the list
void insert_at_end(int element) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;
    temp->next = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = temp;
        temp->prev=NULL;
    } else {
        struct Node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev=temp1;
    }
}

// Function to insert a new node at a specified position in the list
void insert_at_nth(int element, int position) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = element;

    // Insert at the head if position is 1
    if (position == 1) {
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next = head;
        head = temp;
    } else {
        struct Node *temp1 = head;
        for (int i = 1; i < position-1; i++) {
            if (temp1 == NULL) {
                printf("Position out of range\n");
                free(temp);
                return;
            }
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp->prev=temp1;
        temp1->next->prev=temp;
        temp1->next = temp;
    }
}

// Function to delete the node at the beginning of the list
void Delete_from_beg() {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp = head;
        if(temp->next==NULL){
            head=NULL;
        }else{
            struct Node *temp1=temp->next;
            head=temp1;
            temp1->prev=NULL;
        }
        free(temp);
    }
}

// Function to delete the node at the end of the list
void Delete_from_end() {
        struct Node *temp = head;
    if (head == NULL) {
        printf("List is Empty\n");
    } 
else if(temp->next==NULL){
            head=NULL;
   } else {

        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
   
    }
    free(temp);

}

// Function to delete a node at a specified position in the list
void Delete_from_nth_position(int position) {
    if (head == NULL) {
        printf("List is Empty\n");
    } else {
        struct Node *temp = head;

        // If deleting the head node
        if (position == 1) {
            head = head->next;     
                   free(temp);


            return;
        }else{

        for (int i = 1; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range\n");
                return;
            }
            temp = temp->next;
        }

        struct Node *temp1 = temp->next;
         if (temp1 == NULL) {
            printf("Position out of range\n");
            return;
        }
        temp->next = temp1->next;
        temp1->next->prev=temp;
        free(temp1);

    }            

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

