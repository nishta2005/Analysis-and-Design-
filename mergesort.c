#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[] if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[] if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // Recursively sort the first half
        mergeSort(arr, mid + 1, right); // Recursively sort the second half

        merge(arr, left, mid, right); // Merge the sorted halves
    }
}

// Function to generate a random array
void generateRandomArray(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

int main() {
    int N;
    int choice;

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    int arr[N];

    // Ask the user if they want a random array or input their own
    printf("Choose the input method:\n");
    printf("1. Random Array\n");
    printf("2. User Input Array\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Generate a random array
        generateRandomArray(arr, N);

        printf("\n");
    } else if (choice == 2) {
        // Get the array elements from the user
        printf("Enter the elements:\n");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
    } else {
        printf("Invalid choice! Exiting...\n");
        return 1;
    }

    // Record the start time
    clock_t start = clock();

    // Sort the array using merge sort
    mergeSort(arr, 0, N - 1);

    // Record the end time
    clock_t end = clock();

    // Calculate the time taken to sort
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Display the sorted array

    printf("\n");

    // Display the time taken to sort
    printf("Time taken to sort: %.6f seconds\n", time_taken);

    return 0;
}

