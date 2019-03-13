import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class Parabola:
    def __init__(self, focus_x, focus_y, x_left, x_right):
        self.focus = Point(focus_x, focus_y)
        self.x_left, self.x_right = x_left, x_right
    
    def calculate_parabola(self, sweepline_pos, x):
        pass

class Edge:
    def __init__(self):
        pass

class FortuneAlgorithm:
    def __init__(self, field_width, field_height, point_set):
        self.field_width = field_width
        self.field_height = field_height
        self.point_set = point_set
        self.point_set = sorted(self.point_set, key=lambda x: x[1], reverse=True)
        self.point_set = sorted(self.point_set, key=lambda x: x[0], reverse=True)
    
    def site_event(self):
        