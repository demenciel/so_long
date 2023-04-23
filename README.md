# SO_LONG
So Long is a 2D game where the player has to collect all the items and reach the exit. The game is built using the MLX42 library.

## Installation
### Requirements
* GCC
* Make
* MiniLibX library
* CMake

### Building the project
1. Clone the repository
``` bash
git clone <repository_url>
cd <repository_directory>
```

2. Compile and run the project
``` bash
make run
```

## Gameplay
* Use the arrow keys to move the player
* Collect all items
* Reach the exit

## Code Structure
The project is organized into the following directories and files:

* src/: Contains the source code files for the game
    * main.c: Main game loop and initialization
    * map_parsing/: Map parsing and validation
    * map_elements.c
    * map.c
    * map_utils.c
* graphic/: Rendering and handling graphics
    * graphic_main.c
    * graphic_utils.c
    * graphic_move.c
    * graphic_loops.c
    * graphic_img.c
    * graphic_textures.c
* inc/: Contains the header files
    * so_long.h
* map/: Contains the game maps in .ber format
* MLX42/: Contains the MiniLibX library and build files
* Makefile: Build script for the project



