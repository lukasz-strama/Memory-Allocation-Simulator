#ifndef MEMORY_H
#define MEMORY_H

void initialize_memory();
void display_memory();
int allocate_memory(int size);
void deallocate_memory(int start_index, int size);

#endif  // MEMORY_H
