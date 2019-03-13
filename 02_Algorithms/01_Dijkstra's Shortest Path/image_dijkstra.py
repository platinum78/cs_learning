from graph import *
from dijkstra import *
from image_to_graph import *

def main():
    img_to_graph = ImageToGraph("./circle.bmp")
    graph = img_to_graph.image_to_graph()
    
    dijkstra = DijkstraFinder(graph)
    print("here!")
    dijkstra.find_min_path(0, 8100)

if __name__ == "__main__":
    main()