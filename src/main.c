#include <stdio.h>
#include "memory.h"
#include "process.h"
#include "user_interface.h"

int main() {
    initialize_memory();
    display_welcome_message();
    simulation_loop();

    return 0;
}
