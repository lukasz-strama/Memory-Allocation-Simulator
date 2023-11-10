#include "process.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

static int process_count = 0;
static struct Process processes[MAX_PROCESSES];

int create_process(int size) {
    if (process_count < MAX_PROCESSES) {
        processes[process_count].id = process_count + 1;
        processes[process_count].size = size;
        processes[process_count].start_index = -1; // Not allocated initially
        process_count++;
        return process_count;
    } else {
        return -1; // Process limit reached
    }
}

void display_processes() {
    printf("Processes:\n");
    for (int i = 0; i < process_count; i++) {
        printf("ID: %d, Size: %d, Allocated: %s\n",
               processes[i].id, processes[i].size,
               processes[i].start_index != -1 ? "Yes" : "No");
    }
}

int allocate_process_memory(int process_id) {
    int size = processes[process_id - 1].size;
    int start_index = allocate_memory(size, process_count);

    if (start_index != -1) {
        processes[process_id - 1].start_index = start_index;
    }

    return start_index;
}

void deallocate_process_memory(int process_id) {
    int start_index = processes[process_id - 1].start_index;
    int size = processes[process_id - 1].size;
    deallocate_memory(start_index, size);
    processes[process_id - 1].start_index = -1;
}
