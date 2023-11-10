# Memory Allocation Simulator

A simple C project that simulates memory allocation and deallocation. The simulator includes a basic first-fit memory allocation algorithm and allows users to create, allocate, and deallocate memory for processes. This project serves as a starting point for understanding memory management concepts and can be extended with more advanced memory allocation algorithms.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Building the Project](#building-the-project)
- [License](#license)

## Introduction

This project provides a basic memory allocation simulator written in C. It demonstrates a simple first-fit memory allocation algorithm and includes functionalities for creating, allocating, and deallocating memory for processes.

## Features

- First-fit memory allocation algorithm.
- Ability to create processes and allocate/deallocate memory for them.
- User interface for interaction.

## Usage

1. **Building the Project:**
    - Clone the repository.
    - Navigate to the project directory.
    - Run the `make` command to build the project.

2. **Running the Simulator:**
    - Execute the compiled executable (e.g., `./memory_allocation_simulator`).
    - Follow the on-screen instructions to interact with the simulator.

## Building the Project

To build the project, make sure you have a C compiler installed. Navigate to the project directory and run:

```bash
make
```

If you're using VS Code you might want to add:

```json
"includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/include"
            ]
```

into your `.vscode/c_cpp_properties.json` for correct syntax. 

This will compile the source files and create the executable.

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to explore and contribute to the project!
