from heapq import heappush, heappop

class Point:
    def __init__(self, x, y):
        self.x, y = x, y

class Parabola:
    def __init__(self, focus):
        self.focus = focus
        self.x_min = focus.x
        self.x_max = focus.x
    
    def set_domain(self, x_min, x_max):
        self.x_min, self.x_max = x_min, x_max

    def calculate(self, x, sweepline_pos):
        return (x - self.focus.x)**2 / (2 * (self.focus.y - sweepline_pos)) \
             + (self.focus.y + sweepline_pos) / 2

class Line:
    def __init__(self, p1, p2):
        self.p1, self.p2 = p1, p2

class BeachLine:
    def __init__(self, focus):
        self.beachline = []

class SiteEvent:
    def __init__(self, x=None, y=None):
        self.pos = Point(x, y)
        self.parabola = Parabola(self.pos)

class CircleEvent:
    def __init__(self, p1, p2, p3):
        self.pos1 = p1
        self.pos2 = p2
        self.pos3 = p3

class VoronoiMap:
    def __init__(self):
        pass