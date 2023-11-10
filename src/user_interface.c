#include "user_interface.h"
#include <stdio.h>
#include "memory.h"
#include "process.h"

void display_menu() {
    printf("Memory Allocation Simulator\n");
    printf("1. Display Memory\n");
    printf("2. Display Processes\n");
    printf("3. Allocate Memory for Process\n");
    printf("4. Deallocate Memory for Process\n");
    printf("5. Delete Process\n");
    printf("0. Exit\n");
}

void display_welcome_message() {
    printf("Welcome to the Memory Allocation Simulator!\n");
}

void simulation_loop() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_memory();
                break;
            case 2:
                display_processes();
                break;
            case 3:
                allocate_memory_for_process();
                break;
            case 4:
                deallocate_memory_for_process();
                break;
            case 5:
                delete_process_option();
                break;
            case 0:
                printf("Exiting the simulator. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
}

void allocate_memory_for_process() {
    int size;
    printf("Enter the size of the process: ");
    scanf("%d", &size);

    int process_id = create_process(size);
    if (process_id != -1) {
        int start_index = allocate_process_memory(process_id);
        if (start_index != -1) {
            printf("Memory allocated for process ID %d. Start index: %d\n", process_id, start_index);
        } else {
            printf("Memory allocation failed for process ID %d. Insufficient free memory.\n", process_id);
        }
    } else {
        printf("Process creation failed. Maximum number of processes reached.\n");
    }
}

void deallocate_memory_for_process() {
    int process_id;
    printf("Enter the ID of the process to deallocate memory: ");
    scanf("%d", &process_id);

    if (process_id > 0 && process_id <= MAX_PROCESSES) {
        deallocate_process_memory(process_id);
        printf("Memory deallocated for process ID %d.\n", process_id);
    } else {
        printf("Invalid process ID. Please enter a valid ID.\n");
    }
}

void delete_process_option() {
    int process_id;
    printf("Enter the ID of the process to delete: ");
    scanf("%d", &process_id);

    if (process_id > 0 && process_id <= MAX_PROCESSES) {
        delete_process(process_id);
        printf("Process %d deleted.\n", process_id);
    } else {
        printf("Invalid process ID. Please enter a valid ID.\n");
    }
}
