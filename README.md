# Pong Game with Raylib 🏓

A simple implementation of the classic Pong game built using the Raylib library.

![Watch Gameplay Video Preview](gif/gameplay.gif)


##  Features

*   Classic two-player Pong gameplay (Player Vs Ai)
*   Score tracking

##  Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

*   A C/C++ compiler (like GCC/MinGW or the one included with Visual Studio)  C++
*   [Raylib library](https://github.com/raysan5/raylib) installed or set up for your build environment. 📚

### Installation & Running

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/wldoooon/pongGame.git
    cd pongGame
    ```
2.  **Compile the code:**

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

3.  **Run the executable:** ▶️
    *After successful compilation, an executable file (e.g., `pong_game.exe` or similar) will be created.*
    ```bash
    .\pong_game.exe
    ```


## 🎮 How to Play

*   **Player Controls:** ⌨️
    *   Up: `K` key
    *   Down: `J` key
*   **Objective:** Score points by making the ball pass your opponent's paddle. The first player to reach [Your Winning Score] points wins. 🏆

## 🛠️ Built With

*   [Raylib](https://www.raylib.com/) - The game development library used
*   C / C++ - Core language
