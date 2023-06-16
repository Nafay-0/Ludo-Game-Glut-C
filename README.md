# Ludo Game

The Ludo Game repository is an implementation of the popular board game Ludo using Glut C++. The game allows multiple players to compete against each other in a virtual Ludo board.

## Files

The repository contains the following files:

- **CImg.h:** A header file for the CImg library, used for image manipulation and rendering.
- **Makefile:** A Makefile for compiling and building the Ludo game.
- **game.cpp:** The main source code file that implements the game logic and user interface.
- **highscores.txt:** A text file to store the high scores achieved in the game.
- **install-libraries.sh:** A shell script to install the necessary libraries and dependencies for running the game.
- **util.cpp:** A utility source code file that contains helper functions for the game.
- **util.h:** A header file defining the function prototypes and constants used in util.cpp.
- **util.o:** An object file compiled from util.cpp.

## Prerequisites

To run the Ludo Game, make sure you have the following dependencies installed:

- Glut C++ library
- CImg library

## Installation

1. Clone the Repository: Clone this repository to your local machine using Git or download the source code as a ZIP file and extract it.

2. Install Dependencies: Run the `install-libraries.sh` script to install the required libraries and dependencies. Make sure you have the necessary permissions to execute the script.

3. Build the Game: Open a terminal or command prompt in the project directory and run the `make` command. This will compile the source code and generate the executable file.

4. Run the Game: Execute the generated executable file to start the Ludo Game.

## How to Play

1. Launch the Game: Run the Ludo Game executable to start the game.

2. Number of Players: Select the number of players for the game. You can play with 2 to 4 players.

3. Roll the Dice: Each player takes turns rolling the dice. Click on the "Roll Dice" button to generate a random dice value.

4. Move Tokens: To move a token, click on it to select it, and then click on the target position where you want to move the token. The token will be moved automatically.

5. Special Tiles: Be aware of special tiles on the board, such as safe zones and shortcuts, which can affect your progress.

6. Winning the Game: The first player to move all their tokens to the center of the board wins the game.

7. High Scores: The highest scores achieved in the game are stored in the `highscores.txt` file.

## Contributing

Contributions to the Ludo Game repository are welcome! If you have any improvements, bug fixes, or new features, please feel free to submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgements
Special thanks to the Glut C++ community for their valuable resources and support.
