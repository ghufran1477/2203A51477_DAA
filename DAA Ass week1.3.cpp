#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to split a string into an array of integers
int* parse_priority_numbers(char* input, int* size) {
    int* numbers = (int*) malloc(strlen(input) * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    char* token = strtok(input, ",");
    int count = 0;

    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    *size = count;
    return numbers;
}

int main() {
    char input[256];
    int* priority_numbers;
    int size;

    // Taking input for the order priority numbers
    printf("Enter orders Priority Number (comma-separated):\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from the input if present
    input[strcspn(input, "\n")] = 0;

    // Parse the input string into an array of integers
    priority_numbers = parse_priority_numbers(input, &size);
    if (priority_numbers == NULL) {
        return 1;
    }

    // Sort the order priority numbers
    qsort(priority_numbers, size, sizeof(int), compare);

    // Print the sorted order priority numbers
    printf("After Sorting Orders Priority:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", priority_numbers[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");

    // Free allocated memory
    free(priority_numbers);

    return 0;
}

