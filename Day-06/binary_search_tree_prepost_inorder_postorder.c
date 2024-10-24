#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the Binary Search Tree
struct Node
{
    int data;           // Data field to store the node's value
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
};

// Function to create a new node in the BST
struct Node *createNode(int value)
{
    // Dynamically allocate memory for a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    // Set the node's value
    newNode->data = value;
    // Initialize the left and right children as NULL
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode; // Return the new node
}

// Function to insert a new value into the BST
struct Node *insert(struct Node *root, int value)
{
    // If the tree is empty, create a new node as the root
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

    return root; // Return the root node (unchanged)
}

// Function for in-order traversal (left-root-right)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);       // Visit the left subtree
        printf("%d ", root->data); // Print the root's value
        inorder(root->right);      // Visit the right subtree
    }
}

// Function for pre-order traversal (root-left-right)
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Print the root's value
        preorder(root->left);      // Visit the left subtree
        preorder(root->right);     // Visit the right subtree
    }
}

// Function for post-order traversal (left-right-root)
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);     // Visit the left subtree
        postorder(root->right);    // Visit the right subtree
        printf("%d ", root->data); // Print the root's value
    }
}

// Main function to handle menu-driven operations for the BST
void main()
{
    struct Node *root = NULL; // Initialize the BST as empty
    int choice, value;        // Variables for user choice and value input

    while (1)
    {
        // Display the menu options
        printf("\n\n*** BST MENU ***\n");
        printf("1. Insert\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice); // Read user choice

        // Perform operations based on user choice
        switch (choice)
        {
        case 1:
            // Insert a new node
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value); // Insert the value into the BST
            break;
        case 2:
            // In-order traversal
            printf("\nInorder traversal: ");
            inorder(root);
            break;
        case 3:
            // Pre-order traversal
            printf("\nPreorder traversal: ");
            preorder(root);
            break;
        case 4:
            // Post-order traversal
            printf("\nPostorder traversal: ");
            postorder(root);
            break;
        case 5:
            // Exit the program
            exit(0);
        default:
            // Handle invalid choices
            printf("\nInvalid choice! Try again.");
        }
    }
}
