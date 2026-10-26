
*This project has been created as part of the 42 curriculum by sdabbas, jdelmott* 

# CUB3D

## Description

Create a “realistic” 3D graphical
representation of the inside of a maze from a
first-person perspective. You have to create this
representation using the ray-casting principles in the same way as Wolfenstein.

### Objectifs :
- render a 3D map that you read from a `.cub` file  
- the file must contain : <br />
&emsp; - A floor and cieling line with r,g,b colors ( ex: F 255,153,0 )  
&emsp; - The path to each of the wall textures (N, S, E, W)  
&emsp; - A map surrounded by walls   
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

## Instructions

### Compilation
```bash
make        # create the cub3D executable
make clean  # erase every obj files
make fclean # erase every obj files and the executable
make re     # recreate the cub3D executable
```

### test the game :
&emsp; `./cub3D map/<map.cub>`

### how to play :
| Key / Input    | Action                       |
|----------------|------------------------------|
|   **`W`**	 | go forward        |
|   **`A`** | go left      |
|      **`S`** 	 | go backward        |
|      **`D`**	 | go right      |
| **`ESC`** / **`×`** | leave the game               |
| **`←`**      | look left |
| **`→`**	  | look right |

## Resources

### doc
- https://harm-smits.github.io/42docs/libs/minilibx getting_started.html &emsp; -> how to use the minilibx
- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx &emsp; -> how to use the minilibx

### IA Usage

IA was used to understand the raycasting algorithm and it's mathematical equations

### tools

- https://github.com/42paris/minilibx-linux.git &emsp; -> minilibx
- https://convertio.co/fr/png-xpm/ &emsp; -> xpm converter

### README doc
- https://terpconnect.umd.edu/~zben/Web/CharSet/htmlchars.html &emsp; -> non ascii characters (←, ↑, →, ↓, ×) 




