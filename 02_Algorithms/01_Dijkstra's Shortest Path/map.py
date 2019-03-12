class MapNode:
    def __init__(self, index, name=None):
        self.index = index
        self.name = name
        self.adjacent = {}
    
    def __str__(self):
        return "{ index: %d, name: %s }" % (self.index, self.name)
    
    def add_adjacent(self, node, dist):
        self.adjacent[node] = dist

class Map:
    def __init__(self, node_cnt):
        self.node_cnt = node_cnt
        self.nodes = []

        for x in range(self.node_cnt):
            self.nodes.append(MapNode(x))
    
    def connect_nodes(self, idx1, idx2, dist):
        node1 = self.nodes[idx1]
        node2 = self.nodes[idx2]
        node1.add_adjacent(node2, dist)
        node2.add_adjacent(node1, dist)