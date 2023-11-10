#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000

static char memory[MEMORY_SIZE];

void initialize_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
    }
}

void display_memory() {
    printf("Memory: ");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        printf("%c", memory[i] ? 'X' : '.');
    }
    printf("\n");
}

int allocate_memory(int size) {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0) {
            int j;
            for (j = i; j < i + size; j++) {
                if (memory[j] != 0) {
                    break;
                }
            }

            if (j == i + size) {
                for (int k = i; k < j; k++) {
                    memory[k] = 1;
                }
                return i;
            }
        }
    }

    return -1;
}

void deallocate_memory(int start_index, int size) {
    for (int i = start_index; i < start_index + size; i++) {
        memory[i] = 0;
    }
}
