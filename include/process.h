#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESSES 10

struct Process {
    int id;
    int size;
    int start_index;
};

int create_process(int size);
void display_processes();
int allocate_process_memory(int process_id);
void deallocate_process_memory(int process_id);

#endif  // PROCESS_H
