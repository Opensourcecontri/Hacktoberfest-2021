import random
import re

class BOX:
    def __init__(self,dim_sz , mines):

        self.dim_sz = dim_sz # keeping track of the size
        self.mines = mines # keeping track of mines 
        self.checked = set() #to keep track of locations that have been checked
        self.board = self.board_maker() # the main stuff
        self.board_vals()

    def board_maker(self): # making of board (mines)
        #board = [[0]*self.dim_sz]*self.dim_sz
       # board = [ [None for i in range(self.dim_sz)] for i in range(self.dim_sz) ] # made an empty grid
        board = [[10 for i in range(self.dim_sz)] for j in range(self.dim_sz)]
        mines_to_plant = self.mines # taking in number of mines to plant
        #print(board)
        while mines_to_plant > 0: 
            row = random.randint(0,self.dim_sz-1) # picking up row and col for each mine
            col = random.randint(0,self.dim_sz-1)
            if board[row][col] == 10:
                board[row][col] = 9 # planting a mine
                mines_to_plant -= 1
        return board
    def board_vals(self):
        for i in range(self.dim_sz):
            for j in range(self.dim_sz): #O(n^2) loop
                if self.board[i][j] == 10: 
                    self.board[i][j] =  self.get_mines(i,j) # placing number of mines, where there are no mines

    def get_mines(self,i,j): # a simple fxn to get no. of mines
        val = 0
        for r in range( max(0,i-1) , min(self.dim_sz-1,i+1)+1 ): #min , max fxn make sure, it says in range
            for c in range( max(0,j-1) , min(self.dim_sz-1,j+1)+1 ): # checks all the blocks around the chosen box
                if self.board[r][c] == 9: val = val + 1 # yes, it counts original box, which fails this condition and is not counted
        return val

    def dig(self,i,j): # digging function
        self.checked.add((i,j)) #first adding the box to set 
        val = int(self.board[i][j])
        if val == 9:
            return False # mine was found
        elif val > 0: 
            return True # no mine, number was found

        for r in range( max(0,i-1) , min(self.dim_sz-1,i+1)+1 ): # O(n^2) loop with 
            for c in range( max(0,j-1) , min(self.dim_sz-1,j+1)+1 ): # range checks
                if(r,c) in self.checked: continue # to make sure there are no copies in the checked set
                self.dig(r,c) # adding checked out parts recurssively
        return True # we don't dig bombs here, so we always return true
    
    
        
    def visible_part(self):
        visible_board = [[None for _ in range(self.dim_sz)] for _ in range(self.dim_sz)]
        for row in range(self.dim_sz):
            for col in range(self.dim_sz):
                if (row,col) in self.checked:
                    visible_board[row][col] = self.board[row][col]
                else:
                    visible_board[row][col] = 10
        return visible_board
    
    def actual_board(self):
        visible_board = [[None for _ in range(self.dim_sz)] for _ in range(self.dim_sz)]
        for row in range(self.dim_sz):
            for col in range(self.dim_sz):
                    visible_board[row][col] = self.board[row][col]
        '''
        #print(visible_board[0][0])
        for i in range(self.dim_sz):
            for j in range(self.dim_sz):
                print(visible_board[i][j],end=" ")
            print(' ')
            '''
        return visible_board

#play function
def play(dim_sz = 10 , mines = 10):
    Board = BOX(dim_sz,mines)
    print(Board)
    print(Board.actual_board())
    print(Board.visible_part())

if __name__ == '__main__':
    play()