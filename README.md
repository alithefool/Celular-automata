

# Cellular Automata - Game of Life

## Overview
This project implements a **Cellular Automaton**, specifically the **Game of Life**, which is a zero-player game developed by **John Conway**. The game involves a grid of cells that evolve based on a set of rules, with each cell either being **alive** or **dead**. The state of the grid evolves over time, providing interesting patterns and simulations.

### Key Features:
- **Grid-based simulation** with customizable dimensions (rows and columns).
- **Basic interaction** for setting the initial state of the grid.
- **Game of Life rules**: Each cell interacts with its eight neighbors (horizontally, vertically, diagonally) to determine whether it will live, die, or spawn.
- **Multiple generations** of the grid are displayed, showing how the pattern evolves over time.
- **File-based input** to set initial grid configurations (e.g., gliders, pulsars, etc.).

---

## Project Structure

```
/celular_Automata
│
├── /src                # Source code files
│   ├── game_of_life.c  # Main C program implementing the Game of Life
│   └── run_game_of_life.sh  # Shell script to run the program
│
├── /examples           # Folder with example initial grids
│   ├── glider.txt      # Glider pattern example
│   ├── beacon.txt      # Beacon pattern example
│   └── pulsar.txt      # Pulsar pattern example
│
├── README.md           # Project description (this file)
└── Makefile            # Makefile to automate build process
```

---

## History of the Game of Life

The **Game of Life** (often simply referred to as "Life") was created by the British mathematician **John Horton Conway** in **1970**. It is a **cellular automaton** in which cells on a grid evolve over discrete time steps according to simple rules based on their neighbors. Conway’s game was designed to simulate how life might evolve, and it’s capable of generating a variety of complex patterns from simple initial configurations.

### Key Historical Points:
- **Origin**: Conway developed the Game of Life while at the University of Cambridge in 1970. He was inspired by cellular automata, a mathematical concept first introduced by **John von Neumann**.
- **Simple Rules**: Despite the simplicity of its rules, the Game of Life exhibits complex behaviors and patterns, which has fascinated mathematicians, scientists, and hobbyists for decades.
- **The Rules**:
  - **Underpopulation**: A cell with fewer than two live neighbors dies (i.e., becomes dead).
  - **Survival**: A cell with two or three live neighbors stays alive.
  - **Overpopulation**: A cell with more than three live neighbors dies.
  - **Reproduction**: A dead cell with exactly three live neighbors becomes alive.
  
- **Impact**: The Game of Life was one of the first examples of a **computer simulation** of complex behavior emerging from simple rules. It influenced the study of artificial life and cellular automata.

- **Famous Patterns**: Over time, many interesting patterns have emerged from the Game of Life. These include:
  - **Gliders**: A small pattern that moves diagonally across the grid.
  - **Oscillators**: Patterns that repeat themselves after a fixed number of steps (e.g., beacon, pulsar).
  - **Spaceships**: Patterns that translate across the grid (e.g., the "Glider" and "Lightweight Spaceship").

---

## How to Run the Program

### 1. **Clone or Download the Project**

First, clone or download this project to your local machine:

```bash
git clone https://github.com/your_username/cellular_automata.git
cd cellular_automata
```

### 2. **Compile the Program**

Navigate to the `src` folder and compile the source code using `gcc`:

```bash
cd src
gcc game_of_life.c -o game_of_life
```

### 3. **Run the Program**

Run the program directly by executing the compiled binary:

```bash
./game_of_life
```

### 4. **Load an Example File**

You can load an example grid file located in the `/examples` folder by providing the filename as a command-line argument when running the program:

```bash
./game_of_life glider.txt
```

This will initialize the grid with the **Glider pattern** and start the simulation.

---

## Customizing the Grid

- You can customize the grid dimensions (rows and columns) by editing the `#define ROWS` and `#define COLS` values in the `game_of_life.c` file.
- The program will prompt you to enter whether to **load a file** or **create a new random grid**.

---

## Game of Life Rules

The game follows these simple rules for each cell in the grid:
1. **Underpopulation**: A cell with fewer than 2 live neighbors dies (i.e., becomes dead).
2. **Survival**: A cell with 2 or 3 live neighbors stays alive.
3. **Overpopulation**: A cell with more than 3 live neighbors dies.
4. **Reproduction**: A dead cell with exactly 3 live neighbors becomes alive.

---

## Example Patterns

Here are a few example files you can use with the program to start different patterns.

- **Glider (`glider.txt`)**: A small pattern that moves diagonally across the grid.
- **Beacon (`beacon.txt`)**: A stable pattern with periodic oscillations.
- **Pulsar (`pulsar.txt`)**: A more complex pattern that oscillates.

To load one of these patterns, simply run:

```bash
./game_of_life pulsar.txt
```

---

## Dependencies

- **GCC**: Ensure you have GCC installed to compile the program.
- **Standard C Library**: This program uses basic C libraries like `stdio.h`, `stdlib.h`, and `unistd.h`, all of which are typically available by default.

---

## Contributing

Feel free to fork the repository, submit pull requests, or report issues if you'd like to contribute to the project.

### How to Contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new pull request.

---

## License

This project is open-source and available under the [MIT License](LICENSE).

---

## Acknowledgments

- Thanks to **John Conway** for creating the Game of Life.
- This project was inspired by the concepts of **Cellular Automata** and the many amazing patterns they can produce.

---
