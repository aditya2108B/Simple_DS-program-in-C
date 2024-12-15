
#include <stdio.h>
#include <stdlib.h>
// Define the structure of a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int ele) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int ele) {
    if (root == NULL) {
        
        return createNode(ele);
    }else{
    if (ele<root->data ) {
        root->left = insert(root->left, ele);
    } else  {
        root->right = insert(root->right, ele);
    }
    return root;
}
}
// Function to find the minimum ele node in the BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int ele) {
    if (root == NULL) {
        return root;
    }

    else if (ele < root->data) {
        root->left = deleteNode(root->left, ele);
    } else if (ele > root->data) {
        root->right = deleteNode(root->right, ele);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root;
            root=root->right;
            free(temp);
            return root;
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
            return root;
        }else{

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
}return root;
}

// In-order traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void  main() {
    struct Node* root = NULL;
    int choice, ele;
    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Post-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ele to insert: ");
                scanf("%d", &ele);
                root = insert(root, ele);
                break;

            case 2:
                printf("Enter ele to delete: ");
                scanf("%d", &ele);
                root = deleteNode(root, ele);
                break;

            case 3:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice<=5);

}
