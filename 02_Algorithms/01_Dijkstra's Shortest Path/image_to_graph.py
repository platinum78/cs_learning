import cv2
import numpy as np
from graph import *

class ImageToGraph:
    def __init__(self, img_path):
        self.image_preprocessor(img_path)

    def image_preprocessor(self, img_path):
        self.img_path = img_path
        self.image = cv2.imread(self.img_path)
        self.image = cv2.resize(self.image, (200, 200))
        if len(self.image.shape) == 3:
            self.image = np.uint8(np.average(self.image, axis=2))
        self.image[self.image < 150] = 0
        self.image[self.image >= 150] = 255
        
        self.height, self.width = self.image.shape

    def image_to_graph(self):
        self.graph = Map(self.height * self.width)
        for h in range(self.height):
            for w in range(self.width):
                adjacency_code = self.inspect_point(h, w)
                if adjacency_code & 0b1000:
                    self.graph.connect_nodes(self.idx_cvt(h, w), self.idx_cvt(h, w + 1), 1)
                if adjacency_code & 0b0100:
                    self.graph.connect_nodes(self.idx_cvt(h, w), self.idx_cvt(h - 1, w), 1)
                if adjacency_code & 0b0010:
                    self.graph.connect_nodes(self.idx_cvt(h, w), self.idx_cvt(h, w - 1), 1)
                if adjacency_code & 0b0001:
                    self.graph.connect_nodes(self.idx_cvt(h, w), self.idx_cvt(h + 1, w), 1)
        return self.graph
    
    def inspect_point(self, r, c):
        # Bit shifting operation: right, top, left, bottom occupies as 0xrtlb
        adjacency_code = 0b1111
        
        h, w= r - 1, c
        if h < 0:
            adjacency_code &= 0b1011
        else:
            if self.image[h, w] < 128:
                adjacency_code &= 0b1011
        
        h, w = r + 1, c
        if h > self.height - 1:
            adjacency_code &= 0b1110
        else:
            if self.image[h, w] < 128:
                adjacency_code &= 0b1110

        h, w = r, c - 1
        if w < 0:
            adjacency_code &= 0b1101
        else:
            if self.image[h, w] < 128:
                adjacency_code &= 0b1101
        
        h, w = r, c + 1
        if w > self.width - 1:
            adjacency_code &= 0b0111
        else:
            if self.image[h, w] < 128:
                adjacency_code &= 0b0111

        return adjacency_code
    
    def idx_cvt(self, r, c):
        return r * self.width + c