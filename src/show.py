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

#initialize font module
pygame.font.init()

# icon
icon = pygame.image.load(IMAGE_SOURCE_DIR + "/orbit-icon.png")
pygame.display.set_icon(icon)

# colors

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
YELLOW = (255, 255, 0)
BLUE = (0, 0, 255)

TIME_STR_FONT_COLOR = WHITE

# functions

def read_coord_file(path):
    lines = []
    
    with open(path, 'r') as f:
        lines = f.readlines()
        f.close()
        
    return lines

def create_font(name, size):
    # initialize pygame fonts
    my_font = pygame.font.SysFont(name, size)
    return my_font


def render_time_str(font, line_lst, line_i, elem_sep, elem_i, color, antialias=False):
    # render the time string given a line
    return font.render(line_lst[line_i].split(elem_sep)[elem_i].strip(), antialias, color)

def get_coordinates(lines, font, font_color, font_antialias=False):
    # get (x, y) , time_str from lines
    coords = []
    time_render_lst = []
    
    elem_seperator = " "
    
    x_coord_index = 0;
    y_coord_index = 1
    time_str_index = 2
    
    
    for line_i in range(0, len(lines)):
        x = float(lines[line_i].split(elem_seperator)[x_coord_index])
        y = float(lines[line_i].split(elem_seperator)[y_coord_index])

        time_render_lst.append(render_time_str(font, lines, line_i, elem_seperator, time_str_index, font_color, font_antialias))

        coords.append((x, y))
    
    return (coords, time_render_lst)

def draw(Surface, coordinates, radius, color):
    x, y = coordinates
    x = x * SCALE + WIDTH / 2
    y = y * SCALE + HEIGHT / 2

    pygame.draw.circle(Surface, color, (x, y), radius)



font_comic_sans_ms_30 = create_font('Comic Sans MS', 30)

lines = read_coord_file(COORDINATE_FILE)

coord_i = 0
coords, time_render_lst = get_coordinates(lines, font_comic_sans_ms_30, TIME_STR_FONT_COLOR)




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


    draw(screen, (x, y), 20, BLUE)
    screen.blit(time_render_lst[coord_i], (0,0))

    if coord_i + 1 != len(lines):
        coord_i += 1
    else:
        coord_i = 0
    
    
    pygame.display.update()
    Clock.tick(FPS)