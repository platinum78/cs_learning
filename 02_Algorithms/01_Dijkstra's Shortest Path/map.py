class MapNode:
    def __init__(self, index, name=None):
        self.index = index
        self.name = name
        self.adjacent = []
    
    def add_adjacent(self, node):
        self.adjacent.append(node)

class Map:
    def __init__(self, node_cnt):
        self.node_cnt = node_cnt
        self.nodes = []
        
        for x in range(node_cnt):
            self.nodes.append(MapNode(x))
        
    def connect_nodes(self, node1_idx, node2_idx):
        self.nodes[node1_idx].adjacent.append(self.nodes[node2_idx])
        self.nodes[node2_idx].adjacent.append(self.nodes[node1_idx])