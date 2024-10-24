#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Node in the Binary Search Tree (BST)
struct Node
{
    int data;           // Data value of the node
    struct Node *left;  // Pointer to the left child
    struct Node *right; // Pointer to the right child
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the new node
    newNode->data = value;                                             // Set the node's data value
    newNode->left = NULL;                                              // Initially, the left child is NULL
    newNode->right = NULL;                                             // Initially, the right child is NULL
    return newNode;                                                    // Return the created node
}

// Function to insert a new value into the BST
struct Node *insert(struct Node *root, int value)
{
    // Base case: If the tree is empty, create a new node and return it
    if (root == NULL)
    {
        return createNode(value);
    }

    // If the value is less than the root's value, insert in the left subtree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the root's value, insert in the right subtree
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root; // Return the updated root pointer
}

// Function to search for a value in the BST
struct Node *search(struct Node *root, int key)
{
    // Base case: root is NULL or key is present at root
    if (root == NULL || root->data == key)
    {
        return root;
    }

    // If key is less than root's data, search in the left subtree
    if (key < root->data)
    {
        return search(root->left, key);
    }

    // If key is greater than root's data, search in the right subtree
    return search(root->right, key);
}

// Function to perform in-order traversal of the BST (left-root-right)
void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);  // Visit the left subtree
        printf("%d ", root->data);     // Print the root's data
        inOrderTraversal(root->right); // Visit the right subtree
    }
}

int main()
{
    struct Node *root = NULL; // Create an empty tree (initially, root is NULL)
    int choice, value, key;
    struct Node *searchResult;

    while (1)
    {
        printf("\n\n*** BINARY SEARCH TREE MENU ***\n");
        printf("1. Insert a node\n");
        printf("2. Search for a value\n");
        printf("3. Display in-order traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("\nValue %d inserted into the BST.\n", value);
            break;

        case 2:
            printf("Enter the value to search: ");
            scanf("%d", &key);
            searchResult = search(root, key);
            if (searchResult != NULL)
            {
                printf("\nValue %d found in the BST.\n", key);
            }
            else
            {
                printf("\nValue %d not found in the BST.\n", key);
            }
            break;

        case 3:
            printf("\nIn-order Traversal of the BST: ");
            inOrderTraversal(root);
            printf("\n");
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
