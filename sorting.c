
#include <stdio.h>
#define MAX 100

// Function prototypes
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void radixSort(int arr[], int n);
void Display(int arr[], int n);
int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);

void  main() {
    int arr[MAX], n, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nChoose the sorting algorithm:\n");
    printf("1. Selection Sort\n2. Insertion Sort\n3. Radix Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(arr, n);
            printf("\nArray after Selection Sort:\n");
             Display(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            printf("\nArray after Insertion Sort:\n");
             Display(arr, n);
            break;
        case 3:
            radixSort(arr, n);
            printf("\nArray after Radix Sort:\n");
             Display(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // Find the maximum number

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

// Helper function to find the maximum element in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Count Sort used by Radix Sort
void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Update count[i] to store the position of the next element
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to print the array
void Display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
