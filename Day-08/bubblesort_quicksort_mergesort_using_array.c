#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a; // Store the value of *a in temp
    *a = *b;       // Assign the value of *b to *a
    *b = temp;     // Assign the value of temp to *b
}

// Bubble Sort Algorithm: Sorts the array in ascending order
void bubbleSort(int arr[], int n)
{
    // Outer loop for traversing all elements
    for (int i = 0; i < n - 1; i++)
    {
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++)
        {
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]); // Swap the elements
            }
        }
    }
}

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Set the last element as the pivot
    int i = (low - 1);     // Index of smaller element

    // Traverse through the array and rearrange elements based on pivot
    for (int j = low; j <= high - 1; j++)
    {
        // If the current element is smaller than the pivot, swap it
        if (arr[j] < pivot)
        {
            i++;                    // Increment the index of smaller element
            swap(&arr[i], &arr[j]); // Swap arr[i] and arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place the pivot in its correct position
    return (i + 1);                // Return the pivot index
}

// Quick Sort Algorithm: Recursively sorts the array using divide and conquer
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Get the pivot index
        quickSort(arr, low, pi - 1);        // Recursively sort the left partition
        quickSort(arr, pi + 1, high);       // Recursively sort the right partition
    }
}

// Function to merge two subarrays for Merge Sort
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1; // Size of the left subarray
    int n2 = r - m;     // Size of the right subarray

    int L[n1], R[n2]; // Temporary arrays to hold subarrays

    // Copy data into the temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    // Merge the subarrays into the original array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i]; // Take element from the left array
            i++;
        }
        else
        {
            arr[k] = R[j]; // Take element from the right array
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the left array (if any)
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the right array (if any)
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort Algorithm: Recursively divides and merges the array
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;  // Find the middle point
        mergeSort(arr, l, m);     // Recursively sort the left half
        mergeSort(arr, m + 1, r); // Recursively sort the right half
        merge(arr, l, m, r);      // Merge the sorted halves
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]); // Print each element of the array
    }
    printf("\n"); // Newline after printing the array
}

int main()
{
    int arr[100], n, choice; // Declare an array, number of elements, and user choice

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sorting menu loop
    while (1)
    {
        // Display sorting options
        printf("\n\n*** Sorting Menu ***\n");
        printf("1. Bubble Sort\n2. Quick Sort\n3. Merge Sort\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort(arr, n); // Perform Bubble Sort
            printf("Sorted array using Bubble Sort: ");
            printArray(arr, n); // Print the sorted array
            break;
        case 2:
            quickSort(arr, 0, n - 1); // Perform Quick Sort
            printf("Sorted array using Quick Sort: ");
            printArray(arr, n); // Print the sorted array
            break;
        case 3:
            mergeSort(arr, 0, n - 1); // Perform Merge Sort
            printf("Sorted array using Merge Sort: ");
            printArray(arr, n); // Print the sorted array
            break;
        case 4:
            return 0; // Exit the program
        default:
            printf("Invalid choice! Try again.\n"); // Handle invalid input
        }
    }

    return 0;
}
