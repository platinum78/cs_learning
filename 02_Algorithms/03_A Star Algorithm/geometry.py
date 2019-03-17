import cv2
import numpy as np

DIR_EE, DIR_NE, DIR_NN, DIR_NW, DIR_WW, DIR_SW, DIR_SS, DIR_SE = 0, 1, 2, 3, 4, 5, 6, 7

class GridMapNode:
    def __init__(self, x, y):
        self.x, self.y = x, y
        self.adjacency = 0b0
    
    def mark_adjacent(self, direction):
        self.adjacency |= (0b00000001 << direction)

    def unmark_adjacent(self, direction):
        self.adjacency &= 0b11111111 ^ (0b00000001 << direction)
    
    def is_adjacent(self, direction):
        return bool(self.adjacency & (0b00000001 << direction))
    
    def set_adjacency(self, code):
        self.adjacency = code

class GridMap:
    def __init__(self, abs_width, abs_height, grid_size):
        self.abs_width, self.abs_height = abs_width, abs_height
        self.grid_size = grid_size
        self.X = np.ndarray.tolist(np.arange(0, self.abs_width, self.grid_size)).append(self.abs_width)
        self.Y = np.ndarray.tolist(np.arange(0, self.abs_height, self.grid_size)).append(self.abs_height)
        self.grid_width = len(self.X)
        self.grid_height = len(self.Y)
        self.grid_map = []
        for idx_y, y in enumerate(Y):
            grid_row = []
            for idx_x, x in enumerate(X):
                grid_row.append(GridMapNode(x, y))
    
    def connect_nodes(self, x, y, direction):
        node = self.grid_map[y][x]
        node.mark_adjacent(direction)
        