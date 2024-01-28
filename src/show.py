import os
os.environ["PYGAME_HIDE_SUPPORT_PROMPT"] = "1"
os.chdir("../")
print(os.getcwd())

import sys

import pygame
pygame.init()

# Global Variables
IMAGE_SOURCE_DIR = "img"
COORDINATE_FILE = "coordinates/coordinates.txt"



WIDTH, HEIGHT = (800, 800)
FPS = 60

SCALE = 250 / 149.6e9
TIME_STEP = 60*60*24


screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Orbits")

# icon
icon = pygame.image.load(IMAGE_SOURCE_DIR + "/orbit-icon.png")
pygame.display.set_icon(icon)

# colors

BLACK = (0, 0, 0)



def get_coordinates(path):
    
    lines = []
    
    with open(path, 'r') as f:
        lines = f.readlines()
        f.close()
    
    return lines


def draw(coordinates, scale, timestep):
    pass

lines = get_coordinates(COORDINATE_FILE)

Clock = pygame.time.Clock()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            pygame.quit()
            sys.exit()
    
    screen.fill(BLACK)
    
    
    pygame.display.update()
    Clock.tick(FPS)