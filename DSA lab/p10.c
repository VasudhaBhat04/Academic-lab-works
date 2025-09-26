#include<stdio.h>
#include<stdlib.h>

// Node structure for Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the Binary Tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to traverse the Binary Tree in Inorder
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to traverse the Binary Tree in Preorder
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to traverse the Binary Tree in Postorder
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to search for a key in the Binary Tree
struct Node* searchKey(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchKey(root->left, key);
    }

    return searchKey(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int choice, data, key;
    struct Node* result;

    do {
        printf("\nMenu:\n");
        printf("1. Create a BT of N Integers\n");
        printf("2. Traverse the BT in Inorder\n");
        printf("3. Traverse the BT in Preorder\n");
        printf("4. Traverse the BT in Postorder\n");
        printf("5. Search the BT for a given element (KEY)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            
               case 1:
    printf("Enter the number of elements in the Binary Tree: ");
    scanf("%d", &data);

    for (int i = 0; i < data; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        root = insertNode(root, element);
    }
    break;


            case 2:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;


            case 3:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                result = searchKey(root, key);
                if (result != NULL) {
                    printf("Element %d found in the Binary Tree.\n", key);
                } else {
                    printf("Element %d not found in the Binary Tree.\n", key);
                }
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}
