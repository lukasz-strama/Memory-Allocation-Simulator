#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000

static char memory[MEMORY_SIZE];
static int colorMap[MEMORY_SIZE]; 

void initialize_memory() {
    for (int i = 0; i < MEMORY_SIZE; i++) {
        memory[i] = 0;
        colorMap[i] = 0;
    }
}

void display_memory() {
    printf("Memory: ");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] == 0) {
            printf(".");
        } else {
            // Use ANSI escape codes for colors (Assuming process IDs start from 1)
            printf("\033[38;5;%dmX\033[0m", (colorMap[i] * 17) + 31); // Color based on colorMap value
        }
    }
    printf("\n");
}

int allocate_memory(int size, int color) {
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
                    colorMap[k] = color;
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
        colorMap[i] = 0;
    }
}
