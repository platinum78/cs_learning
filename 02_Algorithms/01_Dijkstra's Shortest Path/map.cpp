#include <string>
#include <list>
#include <vector>

class MapNode
{
  public:
    MapNode() : index(-1) {}
    MapNode(int idx, char *name_) : index(idx), name(name_) {}
    void addAdjacent(MapNode *pNode);

  private:
    int index;
    std::string name;
    std::list<MapNode *> adjacent;
};

void MapNode::addAdjacent(MapNode *pNode)
{
    adjacent.push_back(pNode);
}

class Map
{
  public:
    Map();
    Map(int node_cnt);
    void connectNodes(int idx1, int idx2);
    void connectNodes(MapNode *pNode1, MapNode *pNode2);
    int getNodeCount();
    MapNode* getNodeByIdx(int idx);

  private:
    int nodeCnt;
    std::vector<MapNode *> nodes;
};

Map::Map() : nodeCnt(0)
{
    nodes.resize(0);
}

Map::Map(int node_cnt) : nodeCnt(node_cnt)
{
    nodes.resize(node_cnt);
}

void Map::connectNodes(MapNode *pNode1, MapNode *pNode2)
{
    pNode1->addAdjacent(pNode2);
    pNode2->addAdjacent(pNode1);
}

void Map::connectNodes(int idx1, int idx2)
{
    MapNode *pNode1 = nodes[idx1];
    MapNode *pNode2 = nodes[idx2];
    connectNodes(pNode1, pNode2);
}

int Map::getNodeCount()
{
    return nodeCnt;
}

MapNode* Map::getNodeByIdx(int idx)
{
    return (MapNode*)nodes[idx];
}