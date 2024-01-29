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
FPS = 120

SCALE = 250 / 149.6e9
TIME_STEP = 60*60*24


screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Orbits")

# icon
# icon = pygame.image.load(IMAGE_SOURCE_DIR + "/orbit-icon.png")
# pygame.display.set_icon(icon)

# colors

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
BLUE = (0, 0, 255)



def get_coordinates(path):
    
    lines = []
    
    with open(path, 'r') as f:
        lines = f.readlines()
        f.close()
    
    return lines


#fonts
pygame.font.init()
my_font = pygame.font.SysFont('Comic Sans MS', 30)




lines = get_coordinates(COORDINATE_FILE)
coord_i = 0

coords = []
time_render_lst = []
for line in range(0, len(lines)):
    x = float(lines[line].split(" ")[0])
    y = float(lines[line].split(" ")[1])

    time_render_lst.append(my_font.render(lines[line].split(" ")[2].strip(), False, WHITE))

    coords.append((x, y))

coord_num = 0


def draw(Surface, coordinates, radius, color):
    x, y = coordinates
    x = x * SCALE + WIDTH / 2
    y = y * SCALE + HEIGHT / 2

    pygame.draw.circle(Surface, color, (x, y), radius)








Clock = pygame.time.Clock()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
            pygame.quit()
            sys.exit()
    
    screen.fill(BLACK)
    pygame.draw.circle(screen, YELLOW, (WIDTH/2, HEIGHT/2), 30)

    x = coords[coord_i][0]
    y = coords[coord_i][1]

    print(x, y)
    draw(screen, (x, y), 20, BLUE)
    screen.blit(time_render_lst[coord_i], (0,0))

    if coord_i + 1 != len(lines):
        coord_i += 1
    else:
        coord_i = 0
    
    
    
    pygame.display.update()
    Clock.tick(FPS)