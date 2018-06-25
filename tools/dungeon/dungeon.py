import random
import math
import itertools

WIDTH = 50
HEIGHT = 50
MARGIN = 3
PATH_RANDOMNESS = .7
NUM_NODES = 8
NODE_MARGIN = 3

#random.seed(22)

def sgn(x):
    if x < 0: return -1
    elif x > 0: return 1
    return x

cross_neighbourhood = [(-1, 0), (0, -1), (1, 0), (0, 1)]
near_neighbourhood = list(itertools.product(range(-1, 2), range(-1, 2)))
far_neighbourhood = near_neighbourhood + list(itertools.product((-2, 2), range(-1, 2))) + list(itertools.product(range(-1, 2), (-2, 2)))


def get_marginal_nodes():

    nodes = []
    xrange = WIDTH - 2 * MARGIN
    yrange = HEIGHT - 2 * MARGIN

    # Get a node with x coordinates in range MARGIN, MARGIN + xrange / 3
    while True:
        x = random.randint(MARGIN, MARGIN + NODE_MARGIN - 1)
        y = random.randint(MARGIN, MARGIN + yrange - 1)
        if propose_node((x, y), nodes): break
        
    # Get anode with x coordiantes in range MARGIN + 2/3 * xrange, WIDTH - MARGIN
    while True:
        x = random.randint(MARGIN + xrange - 1 - NODE_MARGIN, MARGIN + xrange - 1)
        y = random.randint(MARGIN, MARGIN + yrange - 1)
        if propose_node((x, y), nodes): break

    # Get a node with y coordinates in range MARGIN, MARGIN + xrange / 3
    while True:
        y = random.randint(MARGIN, MARGIN + NODE_MARGIN - 1)
        x = random.randint(MARGIN, MARGIN + xrange - 1)
        if propose_node((x, y), nodes): break
        
    # Get anode with y coordiantes in range MARGIN + 2/3 * xrange, WIDTH - MARGIN
    while True:
        y = random.randint(MARGIN + yrange - 1 - NODE_MARGIN, MARGIN + yrange - 1)
        x = random.randint(MARGIN, MARGIN + xrange - 1)
        if propose_node((x, y), nodes): break

    return nodes


def propose_node(node, nodes):
    if node in nodes: return False
    nodes.append(node)
    return True

def get_nodes():
    xrange = WIDTH - 2 * MARGIN
    yrange = HEIGHT - 2 * MARGIN
    nodes = get_marginal_nodes()


    while len(nodes) < NUM_NODES:
        while True:
            x = random.randint(MARGIN, MARGIN + xrange - 1) 
            y = random.randint(MARGIN, MARGIN + yrange - 1)
            if propose_node((x, y), nodes): break
    return nodes

def connect_sp_step(p, q):
    x0, y0 = p
    x1, y1 = q
    dx = x1 - x0
    dy = y1 - y0
    if abs(dx) >= abs(dy):
        # Chose x
        x0 += sgn(dx)
    else:
        y0 += sgn(dy)
    return x0, y0

def connect_random_step(p, q):
    dx, dy = random.choice(cross_neighbourhood)
    x0, y0 = p
    return x0 + dx, y0 + dy

def connect(p, q, dungeon):
    x0, y0 = p
    x1, y1 = q

    state = 1
    p_keep_state = PATH_RANDOMNESS
    while x0 != x1 or y0 != y1:
        # Check if we keep the state
        if random.random() >= p_keep_state:
            state *= -1 # Switch state
            p_keep_state = PATH_RANDOMNESS
        else:
            p_keep_state *= PATH_RANDOMNESS
        
        if state == 1:
            # Connect by shortest path
            x0_tilde, y0_tilde = connect_sp_step((x0, y0), (x1, y1))
        else:
            # Connect randomly
            x0_tilde, y0_tilde = connect_random_step((x0, y0), (x1, y1))
    
        if x0_tilde not in range(MARGIN, WIDTH-MARGIN) or y0_tilde not in range(MARGIN, HEIGHT-MARGIN):
            continue
        x0, y0 = x0_tilde, y0_tilde
        if dungeon[x0][y0] != "x": dungeon[x0][y0] = " "





def print_dungeon(dungeon):
    for y in range(HEIGHT):
        out = ""
        for x in range(WIDTH):
            out += dungeon[x][y]
        print(out)

def is_wall(x, y, dungeon):
    if x not in range(WIDTH) or y not in range(HEIGHT): return True
    return dungeon[x][y] == "#"

def iterate(lower_bound_near, upper_bound_far, dungeon):
    iterated = [["#" for _ in range(HEIGHT)] for _  in range(WIDTH)]
    for x in range(1, WIDTH - 1):
        for y in range(1, HEIGHT - 1):
            near_walls = 0
            for dx, dy in near_neighbourhood:
                if is_wall(x + dx, y + dy, dungeon): near_walls += 1
            far_walls = 0
            for dx, dy in far_neighbourhood:
                if is_wall(x + dx, y + dy, dungeon): far_walls += 1
            if near_walls >= lower_bound_near or far_walls <= upper_bound_far:
                iterated[x][y] = "#"
            else:
                iterated[x][y] = dungeon[x][y]
    return iterated        

def enlarge(dungeon):
    iterated = [["#" for _ in range(HEIGHT)] for _  in range(WIDTH)]
    for x in range(1, WIDTH - 1):
        for y in range(1, HEIGHT - 1):
            adj_walls = 0
            for dx, dy in cross_neighbourhood:
                if is_wall(x + dx, y + dy, dungeon): adj_walls += 1
            if is_wall(x, y, dungeon) and adj_walls == 4:
                iterated[x][y] = "#"
            else:
                iterated[x][y] = " "
    return iterated


dungeon = [["#" for _ in range(HEIGHT)] for _ in range(WIDTH)]

nodes = get_nodes()
for x, y in nodes: dungeon[x][y] = "x"


for i in range(1, len(nodes)):
    p = random.choice(nodes[:i])
    connect(nodes[i], p, dungeon)

print_dungeon(dungeon)
for _ in range(3): 
    dungeon = enlarge(dungeon)
    print_dungeon(dungeon)
    dungeon = iterate(6, 2, dungeon)
    print_dungeon(dungeon)

print_dungeon(dungeon)