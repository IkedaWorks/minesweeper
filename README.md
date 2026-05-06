💣 Modular Minesweeper in C
This is a classic Minesweeper game developed in C. The primary focus of this repository is to demonstrate the application of Structured Programming and Modularization concepts.

🚀 Project Structure
The game is divided into modules to improve maintainability and code organization:

main.c: Entry point of the program and main execution flow control.

game.c: Implementation of the game logic, including board generation, mine placement, and rule processing.

game.h: Header file containing function prototypes, constant definitions, and structures.

🛠️ How to Compile and Run
As this project does not include pre-compiled binary executables (to ensure portability across different operating systems), you must compile the source code locally.

Prerequisites
You will need a C compiler installed, such as gcc.

Build Instructions:

Clone the repository:

git clone https://github.com/IkedaWorks/minesweeper.git
cd minesweeper

Compile the modules:

gcc main.c game.c -o minesweeper

Run the game:

On Windows:

DOS
minesweeper.exe
On Linux/macOS:

Bash
./minesweeper


⚙️ Development Environment
This project was originally developed using the Code::Blocks IDE. The repository includes a .gitignore file to ensure that IDE-specific files (like .layout and .depend) and build artifacts (the bin/ and obj/ folders) are not tracked.

⚖️ License
This project is licensed under the MIT License.
