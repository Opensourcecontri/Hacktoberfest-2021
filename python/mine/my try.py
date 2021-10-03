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
        board = [[0 for i in range(self.dim_sz)] for j in range(self.dim_sz)]
        mines_to_plant = self.mines # taking in number of mines to plant

        while mines_to_plant > 0: 
            row = random.randint(0,self.dim_sz-1) # picking up row and col for each mine
            col = random.randint(0,self.dim_sz-1)
            if board[row][col] == 0:
                board[row][col] = -1 # planting a mine
                mines_to_plant -= 1
        return board
    def board_vals(self):
        for i in range(self.dim_sz):
            for j in range(self.dim_sz): #O(n^2) loop
                if self.board[i][j] == 0: 
                    self.board[i][j] =  self.get_mines(i,j) # placing number of mines, where there are no mines

    def get_mines(self,i,j): # a simple fxn to get no. of mines
        val = 0
        for r in range( max(0,i-1) , min(self.dim_sz-1,i+1)+1 ): #min , max fxn make sure, it says in range
            for c in range( max(0,j-1) , min(self.dim_sz-1,j+1)+1 ): # checks all the blocks around the chosen box
                if self.board[r][c] == -1: val = val + 1 # yes, it counts original box, which fails this condition and is not counted
        return val

    def dig(self,i,j): # digging function
        self.checked.add((i,j)) #first adding the box to set 
        val = int(self.board[i][j])
        if val == -1:
            return False # mine was found
        elif val > 0: 
            return True # no mine, number was found

        for r in range( max(0,i-1) , min(self.dim_sz-1,i+1)+1 ): # O(n^2) loop with 
            for c in range( max(0,j-1) , min(self.dim_sz-1,j+1)+1 ): # range checks
                if(r,c) in self.checked: continue # to make sure there are no copies in the checked set
                self.dig(r,c) # adding checked out parts recurssively
        return True # we don't dig bombs here, so we always return true
    
    def __str__(self):
        # this is a magic function where if you call print on this object,
        # it'll print out what this function returns!
        # return a string that shows the board to the players

        # first let's create a new array that represents what the user would see
        visible_board = [[None for _ in range(self.dim_sz)] for _ in range(self.dim_sz)]
        for row in range(self.dim_sz):
            for col in range(self.dim_sz):
                if (row,col) in self.checked:
                    visible_board[row][col] = str(self.board[row][col])
                else:
                    visible_board[row][col] = ' '
        
        # put this together in a string
        string_rep = ''
        # get max column widths for printing
        widths = []
        for idx in range(self.dim_sz):
            columns = map(lambda x: x[idx], visible_board)
            widths.append(
                len(
                    max(columns, key = len)
                )
            )

        # print the csv strings
        indices = [i for i in range(self.dim_sz)]
        indices_row = '   '
        cells = []
        for idx, col in enumerate(indices):
            format = '%-' + str(widths[idx]) + "s"
            cells.append(format % (col))
        indices_row += '  '.join(cells)
        indices_row += '  \n'
        
        for i in range(len(visible_board)):
            row = visible_board[i]
            string_rep += f'{i} |'
            cells = []
            for idx, col in enumerate(row):
                format = '%-' + str(widths[idx]) + "s"
                cells.append(format % (col))
            string_rep += ' |'.join(cells)
            string_rep += ' |\n'

        str_len = int(len(string_rep) / self.dim_sz)
        string_rep = indices_row + '-'*str_len + '\n' + string_rep + '-'*str_len

        return string_rep
        


#play function
def play(dim_sz = 10 , mines = 10):
    Board = BOX(dim_sz,mines)
    '''
    first make the board
    place boxes, 
    plant numbers and bombs 
    then, user selects a box
         if bomb - game over
         else show a number and continue the loop
         END if only bombs are left
    '''
    while len(Board.checked) < Board.dim_sz ** 2 - Board.mines:
        print(Board)
        user_input = re.split(',(\\s)*' , input("Enter the Grid co-ordinates of where to dig/check: "))
        r , c = int(user_input[0]) , int(user_input[-1]) 
        if r < 0 or r >= Board.dim_sz or c < 0 or c > Board.dim_sz:
            print("Invalid co-ordinated, try again")
            continue
        safe = Board.dig(r,c)
        if not safe: break
    if safe:
        print('You Won!')
    else:
        print('You Lose!')

    Board.checked = [ (r,c) for r in range(Board.dim_sz) for c in range(Board.dim_sz)]
    print(Board)
if __name__ == '__main__':
    play()
