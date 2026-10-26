
*This project has been created as part of the 42 curriculum by sdabbas & jdelmott* 

# CUB3D
<br />

## Description

Create a “realistic” 3D graphical
representation of the inside of a maze from a
first-person perspective. You have to create this
representation using the ray-casting principles in the same way as Wolfenstein.

### Objectifs :
- render a 3D map that you read from a `.cub` file
- there must be one player, that look in a certain direction (N, S, E, W) <br />
- only those characters are allowed : <br />
&emsp; `1` = walls  
&emsp; `0` = floors  
&emsp; `N` = north  
&emsp; `W` = west
&emsp; `E` = east
&emsp; `S` = south 
- only one player is allowed
- the player must be able to walk around the map without going through walls
<br />
<br />

## Instructions

### Compilation
```bash
make        # creat the cub3D executable
make clean  # erase every obj files
make fclean # erase every obj files and the executable
make re     # recreat the cub3D executable
```

### test the game :
&emsp; `./so_long <map.ber>`

### how to play :
| Key / Input    | Action                       |
|----------------|------------------------------|
|   **`W`**	 | go up        |
|   **`A`** | go left      |
|      **`S`** 	 | go down         |
|      **`D`**	 | go right      |
| **`ESC`** / **`×`** / **`Q`**| leave the game               |
| **`←`**      | look left |
| **`→`**	  | look right |
<br /> / 
<br />

## Resources

### doc
- https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html &emsp; -> how to use the minilibx
- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx &emsp; -> how to use the minilibx
- https://www.geeksforgeeks.org/dsa/flood-fill-algorithm/ &emsp; -> flood fill algorithm

### tools
- https://itch.io/game-assets/free/tag-sprites &emsp; -> pixel art library
- https://convertio.co/fr/png-xpm/ &emsp;             -> png to xpm converter
- https://www.piskelapp.com/ &emsp;                   -> modify your pixel art

### README doc
- https://github.com/raveriss/so_long/blob/main/README.md?plain=1 &emsp; -> exemple of a so_long README
- https://terpconnect.umd.edu/~zben/Web/CharSet/htmlchars.html &emsp; -> non ascii characters (←, ↑, →, ↓, ×) 



https://github.com/42paris/minilibx-linux.git 



https://bigconvert.11zon.com/en/jpeg-to-xpm