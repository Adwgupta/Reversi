# [COMP10050] Software Engineering Project I: 
## Assignment 3 - Othello/Reversi Game

> Create a program that manages a game of Othello for two players

### About The Game 
 --- ---
Coloured Edition
![image](https://user-images.githubusercontent.com/71985681/118888023-07103b00-b8f3-11eb-878f-1fc169176bf8.png)

Non-coloured edition
![image](https://user-images.githubusercontent.com/71985681/118888254-53f41180-b8f3-11eb-8fb8-93cf5370b1f3.png)

The game begins with four discs placed in a square in the middle of the grid,
Two with their black side facing up, two with their white side facing up
With the two discs with the same colour on a diagonal with each other, as shown below:
```
 --- --- 
| w | B |
 --- --- 
| w | B |
```
On your turn, you place one piece on the board with your color facing up.
You must place the piece so that an opponent's piece, or a row of opponent's pieces, is flanked by your pieces.
All of the opponent's pieces between your pieces are then turned over to become your color.

The object of the game is to own more pieces than your opponent when the game is over.
The game is over when neither player has a move. 

## Getting Started 
Download your relevant folder depending on wether or not, the terminal/console you will be using can support ANSI escape sequences, or
Download the relevant .exe file from the bin folder
and run:
```
gcc -o main.exe main.c initialize.c turns.c updategame.c pregame.c aftergame.c findmoves.c colour.c ascii.c
main.exe
```
### Documentation
 --- ---
The documentation.txt file contains
How I decided to implement the game logic
How I separated the code into independent modules
Design Choices
Additional info
Sample I/O


### Author:           [Adityaa Gupta](https://github.com/Adwgupta)
### Language(s):      C & CMake 
### Tools:            Git, Visual Studio Code, CLion
### Grade Recieved   
