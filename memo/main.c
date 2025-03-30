#include <stdio.h>
#include <stdlib.h>

/*
 * This code is not from the book The C Programming Language by (Kernighan Ritchie
 * This is more of a stress relief to learn about heap, stack and memory addresses,
 * instead of writing JS/React code.
*/


int main() {
    int size = 5;
    int *heap_array = malloc(size * sizeof(int));

    if (heap_array == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    // Initialize array with values clearly
    for (int i = 0; i < size; i++) {
        heap_array[i] = i * 10;
    }

    // Print the ENTIRE allocated memory starting address clearly
    printf("Heap array allocated at memory address: %p\n", (void *)heap_array);

    // Print each element's value and its specific memory address
    for (int i = 0; i < size; i++) {
        printf(
            "heap_array[%d] = %d at address %p\n",
            i,
            heap_array[i],
            (void *)&heap_array[i]
        );
    }

    // Free memory
    free(heap_array);

    return 0;
}
