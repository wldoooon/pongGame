# Pong Game with Raylib

A simple implementation of the classic Pong game built using the Raylib library.

![Gameplay Screenshot](<# Add path to a screenshot or GIF if you have one, e.g., docs/screenshot.png #>)
*(Optional: Add a screenshot or GIF of your game here. You might need to create a `docs` folder or similar to store images).*

## Features

*   Classic two-player Pong gameplay
*   Score tracking
*   [Add any other features, e.g., Simple AI opponent, Ball speed increase, Sound effects]

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

*   A C/C++ compiler (like GCC/MinGW or the one included with Visual Studio)
*   [Raylib library](https://github.com/raysan5/raylib) installed or set up for your build environment.

### Installation & Running

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/wldoooon/pongGame.git
    cd pongGame
    ```
2.  **Compile the code:**
    *(Provide the specific command(s) needed to compile your project. This depends heavily on your setup. Here are some examples - replace with your actual command)*

    *Example using GCC/MinGW (if raylib is installed system-wide or in a known path):*
    ```bash
    gcc main.c -o pong_game -lraylib -lopengl32 -lgdi32 -lwinmm
    ```
    *Example if using a Makefile:*
    ```bash
    make
    ```
    *Example if using Visual Studio:*
    Open the `.sln` file and build the solution (Ctrl+Shift+B).

3.  **Run the executable:**
    *After successful compilation, an executable file (e.g., `pong_game.exe` or similar) will be created.*
    ```bash
    .\pong_game.exe
    ```
    *(Adjust the executable name if it's different)*

## How to Play

*   **Player 1 Controls:**
    *   Up: `W` key
    *   Down: `S` key
    *   *(Adjust keys if different)*
*   **Player 2 Controls:**
    *   Up: `Up Arrow` key
    *   Down: `Down Arrow` key
    *   *(Adjust keys if different)*
*   **Objective:** Score points by making the ball pass your opponent's paddle. The first player to reach [Your Winning Score] points wins.
*   **Pause:** [Specify pause key if any]
*   **Restart:** [Specify restart key if any]

## Built With

*   [Raylib](https://www.raylib.com/) - The game development library used
*   C / C++ - Core language

## License

*(Optional: Specify a license if you have one, e.g., MIT License. If not, you can remove this section or state that it's unlicensed).*

## Acknowledgments

*(Optional: Mention any tutorials followed, assets used, or people who helped).*