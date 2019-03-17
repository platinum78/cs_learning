from heapq import heapify, heappop, heappush
from graph import *

class DijkstraFinder:
    def __init__(self, graph):
        self.graph = graph
        self.node_cnt = graph.node_cnt
        self.dijkstra_finder_init()
    
    def dijkstra_finder_init(self):
        self.node_list = []
        self.min_path = []
        self.node_dist = {}
        self.node_from = {}
    
        for idx in range(self.node_cnt):
            self.node_dist[self.graph.nodes[idx]] = 0xFFFFFFFF
            self.node_from[self.graph.nodes[idx]] = None
            self.node_list.append(self.graph.nodes[idx])
    
    def find_min_dist_node(self):
        min_dist_node = self.node_list[0]
        for node in self.node_list:
            dist = self.node_dist[node]
            if dist < self.node_dist[min_dist_node]:
                min_dist_node = node
        return min_dist_node

    def find_min_path(self, start, exit_):
        self.dijkstra_finder_init()
        self.node_dist[self.graph.nodes[start]] = 0

        while len(self.node_list) > 0:
            min_dist_node = self.find_min_dist_node()
            self.node_list.pop(self.node_list.index(min_dist_node))

            for adj_node, dist in min_dist_node.adjacent.items():
                new_dist = self.node_dist[min_dist_node] + dist
                if new_dist < self.node_dist[adj_node]:
                    self.node_dist[adj_node] = new_dist
                    self.node_from[adj_node] = min_dist_node
        
        node_backtrack = self.graph.nodes[exit_]
        print("Minimum path distance: ", self.node_dist[node_backtrack])
        while True:
            self.min_path.append(node_backtrack)
            if self.node_from[node_backtrack] == None:
                break
            node_backtrack = self.node_from[node_backtrack]
        self.min_path.reverse()

        for node in self.min_path:
            print(node)

if __name__ == "__main__":
    input_text = ""
    edges = []
    node_cnt = 0
    with open("./input.txt") as input_io:
        node_cnt = int(input_io.readline())
        input_text = input_io.readline()
        while input_text != "":
            input_text = input_text.replace(" ", "")
            input_text = input_text.split(",")
            edge = tuple([int(x) for x in input_text])
            edges.append(edge)
            input_text = input_io.readline()
    
    graph = Map(node_cnt)
    for edge in edges:
        graph.connect_nodes(edge[0], edge[1], edge[2])
    
    dijkstra = DijkstraFinder(graph)
    dijkstra.find_min_path(0, 9)