# Life-Game
Conway's Game of Life implemented in C++

## Game Rules
Life is played on a grid of square cells--like a chess board but extending infinitely in every direction. A cell can be live or dead.   
A live cell is shown by putting a marker on its square. A dead cell is shown by leaving the square empty.  
Each cell in the grid has a neighborhood consisting of the eight cells in every direction including diagonals.

To apply one step of the rules, we count the number of live neighbors for each cell. What happens next depends on this number.  
* A dead cell with exactly three live neighbors becomes a live cell (birth).
* A live cell with two or three live neighbors stays alive (survival).
* In all other cases, a cell dies or remains dead (overcrowding or loneliness).

## UI
Game UI is implemented with EasyX lib.

## Realized Functions
* Reset the seed land to blank.
* Initializing the seed land randomly.
* Develop into the next generation of seeds.
