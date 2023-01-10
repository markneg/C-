#Mark Negus
#Sedoku solver program

import numpy as np

#The starting position
grid = [[0,0,8,9,2,0,3,0,0],
        [9,4,0,0,5,0,0,2,0],
        [6,0,2,0,0,0,8,0,0],
        [0,0,0,0,0,8,9,0,3],
        [5,1,0,3,4,0,6,8,0],
        [3,8,6,1,0,7,0,0,4],
        [0,3,0,0,8,0,0,0,0],
        [8,9,5,0,3,4,0,6,0],
        [0,0,7,2,0,0,5,3,0]]

#checks to see if a move is possible 
def validGuessCheck(row,col,num):
    global grid
#making sure a number is not repeated in the row and column of the entire board
    for x in range(0,9):
        if grid[row][x] == num:
            return False
    for x in range(0,9):
        if grid[x][col] == num:
            return False
#making sure a number is not repeated in it's mini 3x3 square    
    i = (col // 3)*3
    j = (row // 3)*3
    
    for x in range(0,3):
        for y in range(0,3):
            if grid[row+i][col+j] == num:
                return False
                
    return True
    
    def solver():
        global grid
        for row in range(0,9):
            for col in range(0,9):
                for num in range(1,10):
                    if validGuessCheck(row,col,num):
                        grid[row][col] = num
                        solver()
                        grid[row][col] = 0
                return
    print(np.matrix(grid))
