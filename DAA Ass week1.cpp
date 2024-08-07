#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for ascending order
int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to compare two integers for descending order
int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Function to process and sort delivery times
void process_delivery_times(int times[], int size, char order) {
    if (order == 'a') {
        qsort(times, size, sizeof(int), compare_asc);
    } else if (order == 'd') {
        qsort(times, size, sizeof(int), compare_desc);
    } else {
        printf("Invalid order specified. Use 'a' for ascending or 'd' for descending.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d\n", times[i]);
    }
}

int main() {
    int n;
    char order;

    // Taking input for the number of delivery times
    printf("Enter the number of delivery times: ");
    scanf("%d", &n);

    // Dynamically allocate memory for delivery times
    int *times = (int*) malloc(n * sizeof(int));
    if (times == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Taking input for delivery times
    printf("Enter the delivery times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }

    // Taking input for the order of sorting
    printf("Enter the order of sorting (a for ascending, d for descending): ");
    scanf(" %c", &order);

    // Process and display sorted delivery times
    process_delivery_times(times, n, order);

    // Free allocated memory
    free(times);

    return 0;
}

