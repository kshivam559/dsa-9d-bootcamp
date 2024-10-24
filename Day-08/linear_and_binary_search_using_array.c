#include <stdio.h>

// Function for Linear Search: Iterates through the array to find the key
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        // If the element is found, return its index
        if (arr[i] == key)
        {
            return i;
        }
    }
    // If the element is not found, return -1
    return -1;
}

// Function for Binary Search: Efficient search in a sorted array
int binarySearch(int arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2; // Calculate mid index

        // If the key is found at mid, return the index
        if (arr[mid] == key)
        {
            return mid;
        }
        // If the key is greater, ignore the left half
        if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            // If the key is smaller, ignore the right half
            right = mid - 1;
        }
    }
    // If the element is not found, return -1
    return -1;
}

int main()
{
    int arr[100], n, key, choice;

    // Input the number of elements in the array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input the elements of the array
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Infinite loop for the search menu
    while (1)
    {
        // Display the search menu
        printf("\n\n*** Search Menu ***\n");
        printf("1. Linear Search\n2. Binary Search\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Perform Linear Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int linearResult = linearSearch(arr, n, key); // Call linear search function
            if (linearResult != -1)
            {
                printf("Element found at index: %d\n", linearResult); // If element is found, print index
            }
            else
            {
                printf("Element not found.\n"); // If element is not found
            }
            break;
        case 2:
            // Before performing Binary Search, sort the array using Bubble Sort
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        // Swap adjacent elements if they are in the wrong order
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            // Perform Binary Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            int binaryResult = binarySearch(arr, 0, n - 1, key); // Call binary search function
            if (binaryResult != -1)
            {
                printf("Element found at index: %d\n", binaryResult); // If element is found, print index
            }
            else
            {
                printf("Element not found.\n"); // If element is not found
            }
            break;
        case 3:
            // Exit the program
            return 0;
        default:
            // Handle invalid choices
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
