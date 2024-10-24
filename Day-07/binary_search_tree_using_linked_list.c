#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node
{
    int data;           // Data stored in the node
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
};

// Function to create a new node with a given value
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for a new node
    newNode->data = value;                                             // Assign the value to the node's data field
    newNode->left = NULL;                                              // Initialize left child as NULL
    newNode->right = NULL;                                             // Initialize right child as NULL
    return newNode;                                                    // Return the created node
}

// Function to insert a new node into the BST
struct Node *insert(struct Node *root, int value)
{
    // If the tree is empty, create a new node and return it as the root
    if (root == NULL)
    {
        return createNode(value);
    }
    // If the value is less than the current node's data, insert it into the left subtree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    // If the value is greater than the current node's data, insert it into the right subtree
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root; // Return the updated root
}

// Function for inorder traversal (Left, Root, Right)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);       // Traverse left subtree
        printf("%d ", root->data); // Visit the root node (print data)
        inorder(root->right);      // Traverse right subtree
    }
}

// Function for preorder traversal (Root, Left, Right)
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data); // Visit the root node (print data)
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Function for postorder traversal (Left, Right, Root)
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Visit the root node (print data)
    }
}

// Function to search for a specific value in the BST
struct Node *search(struct Node *root, int value)
{
    // If the tree is empty or the value is found, return the root
    if (root == NULL || root->data == value)
    {
        return root;
    }
    // If the value is less than the current node's data, search in the left subtree
    if (value < root->data)
    {
        return search(root->left, value);
    }
    // Otherwise, search in the right subtree
    return search(root->right, value);
}

// Main function to provide menu options for BST operations
void main()
{
    struct Node *root = NULL; // Initialize the root of the BST as NULL
    int choice, value;        // Variables to store user choice and value for operations
    struct Node *result;      // Variable to store the result of the search operation

    // Infinite loop to provide the menu until the user chooses to exit
    while (1)
    {
        // Display menu options
        printf("\n\n*** BINARY SEARCH TREE MENU ***\n");
        printf("1. Insert\n2. Search\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice); // Get the user's choice

        // Perform operations based on user choice
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);        // Get value to insert
            root = insert(root, value); // Insert the value into the BST
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);          // Get value to search for
            result = search(root, value); // Search for the value in the BST
            if (result != NULL)
            {
                printf("\nValue %d found in the BST", value); // Print if found
            }
            else
            {
                printf("\nValue %d not found in the BST", value); // Print if not found
            }
            break;
        case 3:
            printf("\nInorder traversal: ");
            inorder(root); // Perform inorder traversal
            break;
        case 4:
            printf("\nPreorder traversal: ");
            preorder(root); // Perform preorder traversal
            break;
        case 5:
            printf("\nPostorder traversal: ");
            postorder(root); // Perform postorder traversal
            break;
        case 6:
            exit(0); // Exit the program
        default:
            printf("\nInvalid choice! Try again."); // Handle invalid input
        }
    }
}
