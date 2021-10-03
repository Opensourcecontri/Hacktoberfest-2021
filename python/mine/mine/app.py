import pygame
import game_config as gc
import mineswipper as game
from pygame import display, event, image
from time import sleep
import Images

def find_index_from_xy(x, y):
    row = y // gc.IMAGE_SIZE
    col = x // gc.IMAGE_SIZE
    index = row * gc.NUM_TILES_SIDE + col
    return row, col, index

pygame.init()
display.set_caption('Mineswipper')
screen = display.set_mode((gc.SCREEN_SIZE, gc.SCREEN_SIZE))
running = True

board = game.BOX(gc.NUM_TILES_SIDE,gc.MINES)
visible_part = board.visible_part()
actual_part = board.actual_board()

tiles = [[None for _ in range(gc.NUM_TILES_TOTAL)] for _ in range(gc.NUM_TILES_TOTAL)]
for i in range(gc.NUM_TILES_SIDE):
    for j in range(gc.NUM_TILES_SIDE):
        tiles[i][j] = Images.Image(i,j,actual_part[i][j])

def actual_board_display():
    screen.blit(image.load('assets/11.png'), (0, 0))
    display.flip()
    sleep(2.1)
    screen.fill((0, 0, 0))
    for i in range(gc.NUM_TILES_SIDE):
        for j in range(gc.NUM_TILES_SIDE):
            tile = tiles[i][j]
            screen.blit(tile.image, (tile.col * gc.IMAGE_SIZE + gc.MARGIN, tile.row * gc.IMAGE_SIZE + gc.MARGIN))
    display.flip()
    sleep(5)

while running:
    current_events = event.get()

    for e in current_events:
        if e.type == pygame.QUIT:
            running = False

        if e.type == pygame.KEYDOWN:
            if e.key == pygame.K_ESCAPE:
                running = False

        if e.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = pygame.mouse.get_pos()
            row, col, index = find_index_from_xy(mouse_x, mouse_y)
            if row >= gc.NUM_TILES_SIDE or col >= gc.NUM_TILES_SIDE:
                continue
            if (row,col) not in board.checked:
                val = board.dig(row,col)
            if val is False:
                running = False
                print('You Lose!')
                actual_board_display()

                

    # Display 
    screen.fill((0, 0, 0))


    for i in range(gc.NUM_TILES_SIDE):
        for j in range(gc.NUM_TILES_SIDE):
            tile = tiles[i][j]
            current_image = tile.image if (i,j) in board.checked else tile.box
            screen.blit(current_image, (tile.col * gc.IMAGE_SIZE + gc.MARGIN, tile.row * gc.IMAGE_SIZE + gc.MARGIN))

    display.flip()

    if len(board.checked) == gc.NUM_TILES_TOTAL - gc.MINES:
        running = False
        print('You Win!')
        screen.blit(image.load('assets/12.png'), (0, 0))
        display.flip()
        sleep(2.1)

print('Goodbye!')

