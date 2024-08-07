#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compare two integers for ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to split a string into an array of integers
int* parse_product_ids(char* input, int* size) {
    int* ids = (int*) malloc(strlen(input) * sizeof(int));
    if (ids == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    char* token = strtok(input, ",");
    int count = 0;

    while (token != NULL) {
        ids[count++] = atoi(token);
        token = strtok(NULL, ",");
    }

    *size = count;
    return ids;
}

int main() {
    char input[256];
    int* product_ids;
    int size;

    // Taking input for the product IDs
    printf("Enter Product IDs (comma-separated):\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from the input if present
    input[strcspn(input, "\n")] = 0;

    // Parse the input string into an array of integers
    product_ids = parse_product_ids(input, &size);
    if (product_ids == NULL) {
        return 1;
    }

    // Sort the product IDs
    qsort(product_ids, size, sizeof(int), compare);

    // Print the sorted product IDs
    printf("After Sorting Product IDs:\n");
    for (int i = 0; i < size; i++) {
        printf("%d", product_ids[i]);
        if (i < size - 1) {
            printf(",");
        }
    }
    printf("\n");

    // Free allocated memory
    free(product_ids);

    return 0;
}

