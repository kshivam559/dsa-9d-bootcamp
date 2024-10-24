#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the AVL Tree
struct Node
{
    int data;           // Data field to store the node's value
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node
    int height;         // Height of the node for balancing purposes
};

// Function to create a new node in the AVL tree
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value; // Assign the value to the node
    newNode->left = NULL;  // Initialize the left child as NULL
    newNode->right = NULL; // Initialize the right child as NULL
    newNode->height = 1;   // New node's height is initially 1
    return newNode;
}

// Function to get the height of the node
int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0; // Height of NULL node is 0
    }
    return node->height; // Return the height of the node
}

// Utility function to get the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to perform a right rotation on the subtree rooted with 'y'
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;   // 'x' becomes the new root of the subtree
    struct Node *T2 = x->right; // Temporary store 'x's right child

    // Perform the rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return the new root
    return x;
}

// Function to perform a left rotation on the subtree rooted with 'x'
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right; // 'y' becomes the new root of the subtree
    struct Node *T2 = y->left; // Temporary store 'y's left child

    // Perform the rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return the new root
    return y;
}

// Function to get the balance factor of a node
int getBalance(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right); // Balance factor
}

// Function to insert a new value in the AVL Tree
struct Node *insert(struct Node *node, int value)
{
    // Perform the normal BST insertion
    if (node == NULL)
    {
        return createNode(value); // Create a new node if the tree is empty
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value); // Insert in the left subtree
    }
    else if (value > node->data)
    {
        node->right = insert(node->right, value); // Insert in the right subtree
    }
    else
    {
        return node; // Equal values are not allowed in BST/AVL
    }

    // Update height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of the current node to check for imbalance
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && value > node->right->data)
    {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to find the node with the smallest value in the subtree
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the AVL Tree
struct Node *deleteNode(struct Node *root, int value)
{
    // Perform standard BST deletion
    if (root == NULL)
    {
        return root;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Node with one child or no child
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            // Node with two children
            struct Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
    {
        return root;
    }

    // Update height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor to check for imbalance
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for a value in the AVL Tree
struct Node *search(struct Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }

    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// In-order traversal (left-root-right)
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order traversal (root-left-right)
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (left-right-root)
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Main function to handle menu-driven AVL Tree operations
void main()
{
    struct Node *root = NULL;
    int choice, value;

    while (1)
    {
        // Display the menu options
        printf("\n\n*** AVL TREE MENU ***\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Perform operations based on user choice
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value); // Insert value into the AVL Tree
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value); // Delete value from the AVL Tree
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            struct Node *result = search(root, value); // Search for value
            if (result != NULL)
            {
                printf("Value %d found in the AVL Tree", value);
            }
            else
            {
                printf("Value %d not found in the AVL Tree", value);
            }
            break;
        case 4:
            printf("\nInorder traversal: ");
            inorder(root); // Perform in-order traversal
            break;
        case 5:
            printf("\nPreorder traversal: ");
            preorder(root); // Perform pre-order traversal
            break;
        case 6:
            printf("\nPostorder traversal: ");
            postorder(root); // Perform post-order traversal
            break;
        case 7:
            exit(0); // Exit the program
        default:
            printf("Invalid choice! Try again.");
        }
    }
}
