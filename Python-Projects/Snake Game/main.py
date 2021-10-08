import pygame
import time
import random

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
ORANGE = (255, 165, 0)
WIDTH = 600 
HEIGHT = 400
SNAKE_SIZE = 10
SNAKE_SPEED = 10

pygame.init()

MESSAGE_FONT = pygame.font.SysFont('ubuntu', 30)
SCORE_FONT = pygame.font.SysFont('ubuntu', 24)

game_display = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Snake Game")

clock = pygame.time.Clock()

def printScore(score):
    text = SCORE_FONT.render("Score: " + str(score), True, ORANGE)
    game_display.blit(text, [0, 0]);

def drawSnake(snakeSize, snakePixels):
    for pixel in snakePixels:
        pygame.draw.rect(game_display, (255, 255, 255), [pixel[0], pixel[1], SNAKE_SIZE, SNAKE_SIZE])

def runGame():
    gameOver = False
    gameClose = False
    x = WIDTH / 2
    y = HEIGHT / 2
    xSpeed = 0
    ySpeed = 0
    snakePixels = []
    snakeLength = 1
    targetX = round(random.randrange(0, WIDTH - SNAKE_SIZE) / 10.0) * 10.0
    targetY = round(random.randrange(0, HEIGHT - SNAKE_SIZE) / 10.0) * 10.0

    while not gameOver:

        while  gameClose:
            game_display.fill(BLACK)
            gameOverMessage = MESSAGE_FONT.render("Game over!", True, RED)
            game_display.blit(gameOverMessage, [WIDTH / 3, HEIGHT / 3])
            printScore(snakeLength - 1)
            pygame.display.update()

            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_1:
                        gameOver = True
                        gameClose = False
                    if event.key == pygame.K_2:
                        runGame()
                if event.type == pygame.QUIT:
                    gameOver = True
                    gameClose = False
                

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameOver = True
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    xSpeed = -1 * SNAKE_SPEED
                    ySpeed = 0
                if event.key == pygame.K_RIGHT:
                    xSpeed = SNAKE_SPEED
                    ySpeed = 0
                if event.key == pygame.K_UP:
                    xSpeed = 0
                    ySpeed = -1 * SNAKE_SPEED
                if event.key == pygame.K_DOWN:
                    xSpeed = 0
                    ySpeed = SNAKE_SPEED
        
        if x + SNAKE_SIZE >= WIDTH or x < 0 or y  + SNAKE_SIZE >= HEIGHT or y < 0:
            gameClose = True 
        
        x += xSpeed
        y += ySpeed

        game_display.fill(BLACK)
        pygame.draw.rect(game_display, ORANGE, [targetX, targetY, SNAKE_SIZE, SNAKE_SIZE])

        snakePixels.append([x,y])

        if len(snakePixels) > snakeLength:
            del snakePixels[0]

        for pixel in snakePixels[:-1]:
            if pixel == [x, y]:
                gameClose = True

        drawSnake(SNAKE_SIZE, snakePixels)
        printScore(snakeLength - 1)

        pygame.display.update()

        if x == targetX and y == targetY:
            targetX = round(random.randrange(0, WIDTH - SNAKE_SIZE) / 10.0) * 10.0
            targetY = round(random.randrange(0, HEIGHT - SNAKE_SIZE) / 10.0) * 10.0
            snakeLength += 1

        clock.tick(SNAKE_SPEED)
    pygame.quit()
    quit()

runGame()