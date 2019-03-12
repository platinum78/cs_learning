class DijkstraPath:
    def __init__(self, map_):
        self.distance = {}
        self.came_from = {}

        for node in map_.nodes:
            self.distance[node.code] = 100000000
            self.came_from[node.code] = -1
        
        self.min_path = []
    
    def find_min_path(self, min_dist):
        