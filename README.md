# So Long - Game Project

This is the README file for the "So Long" project, a basic 2D game developed as part of the curriculum at 42. The game involves a character collecting collectibles and escaping to a designated exit. Here's an overview of the project and its requirements:

## Table of Contents
- [Project Description](#project-description)
- [Mandatory Part](#mandatory-part)
  - [Game](#game)
  - [Graphic Management](#graphic-management)
  - [Map](#map)
  - [Used Functions](#used-functions)
  - [Official Resources](official-resources)

- [Bonus Part](#bonus-part)

## Project Description

In this project, you will create a 2D game where a character (originally a dolphin in the example) collects items and escapes from the map. You have creative freedom to choose any character, collectibles, or map layout you prefer. The project must adhere to the following rules:

- You must use the MiniLibX library for graphic management.
- A Makefile must be provided to compile the source files without relinking.
- The program takes a map description file with a `.ber` extension as a parameter.

## Mandatory Part

### Game

- The player's objective is to collect all collectibles on the map and then escape using the shortest route.
- Movement is controlled using the W, A, S, and D keys, allowing the character to move up, down, left, and right.
- The player should not be able to move through walls.
- The current number of movements must be displayed in the shell after each move.
- You must use a 2D top-down or profile view for the game.
- The game does not need to be real-time, allowing for turn-based gameplay.

### Graphic Management

- The program must display the game in a window.
- Window management should be smooth, including switching between windows, minimizing, etc.
- Pressing the ESC key should cleanly close the window and exit the program.
- Clicking the close button on the window frame should also cleanly close the program.
- The use of images from MiniLibX is mandatory.

### Map

- The map consists of walls, collectibles, and free space.
- The map is composed of five characters: 0 (empty space), 1 (wall), C (collectible), E (exit), and P (player's starting position).
- The map must contain at least one exit, one collectible, and one starting position to be valid.
- Duplicate characters (exit/start) in the map result in an error.
- The map must be rectangular and surrounded by walls; otherwise, an error is reported.
- Valid path checking within the map is required.
- The program should be able to parse various map layouts as long as they follow the rules.
- Errors in the map file should result in a clean exit and an explicit error message.

## Bonus Part

While the bonus part is not mandatory, you can earn extra points by implementing additional features:

- Player loses when touching an enemy patrol. < Done by me >
- Adding sprite animations.
- Displaying the movement count directly on the screen instead of in the shell. < Done by me >

Please note that this project is primarily intended to teach you graphics and game development concepts. Spend a reasonable amount of time on it and prioritize other assignments and projects.

## Used Functions

| Function         | Description                                                                                              |
|------------------|----------------------------------------------------------------------------------------------------------|
| open             | Opens a file or device for reading or writing.                                                           |
| close            | Closes an open file or device.                                                                          |
| read             | Reads data from a file descriptor.                                                                      |
| write            | Writes data to a file descriptor.                                                                       |
| malloc           | Allocates a block of memory dynamically.                                                                 |
| free             | Releases the memory previously allocated by `malloc`.                                                    |
| perror           | Prints a description for the last error that occurred.                                                   |
| strerror         | Returns a pointer to the textual representation of the current errno value.                              |
| exit             | Terminates the program with an exit status.                                                              |
| Math Library     | All functions of the math library (-lm compiler option, man man 3 math).                                  |
| MiniLibX Library | All functions of the MiniLibX library for graphics.                                                       |
| ft_printf        | Custom implementation of `printf` for formatted output.                                                   |

## Used Functions

### MinilibX Functions

MinilibX is a library used for graphics operations and provides the following MinilibX functions:

| Function           | Description                                                        |
|--------------------|--------------------------------------------------------------------|
| `mlx_init`         | Initializes the MinilibX context and returns a context.             |
| `mlx_new_window`   | Creates a new window and assigns a title to it.                     |
| `mlx_pixel_put`    | Colors a pixel with a specified color on the specified window.     |
| `mlx_loop`         | Starts the event loop and handles window events.                    |
| `mlx_key_hook`     | Captures keyboard events and calls a specified function.           |
| `mlx_mouse_hook`   | Captures mouse events and calls a specified function.              |
| `mlx_hook`         | Used for capturing general events.                                  |
| `mlx_clear_window` | Clears the contents of a window.                                   |
| `mlx_destroy_window`| Closes the specified window and destroys the associated context.  |

### Official Resources

To learn more about MinilibX and get official documentation, you can refer to the following resources:

- [MinilibX Official GitHub Repository](https://github.com/42Paris/minilibx-linux): The official GitHub repository for MinilibX Linux version contains source code and usage examples.
- [MinilibX MacOS Documentation](https://harm-smits.github.io/42docs/libs/minilibx): Detailed information about MinilibX for MacOS is available in this documentation.
- [MinilibX Linux Documentation](https://harm-smits.github.io/42docs/libs/minilibx-linux): Detailed information about MinilibX for Linux is available in this documentation.

These resources will help you get started with MinilibX and graphics programming. If you have any further questions, please don't hesitate to ask.

