#include "map.cpp"
#include <vector>
#include <queue>

class NodeInfo
{
    public:
    NodeInfo(MapNode* p, int idx): pNode(p), index(idx), dist(0) {}

    MapNode* pNode;
    int index;
    int dist;
};

class NodeCmp
{
    public:
    bool operator() (NodeInfo& n1, NodeInfo& n2)
    {
        return n1.dist < n2.dist;
    }
};

class DijkstraExplorer
{
  public:
    DijkstraExplorer(Map &map_);
    void findMinPath(MapNode* pStart, MapNode* pExit);
    void findMinPath(int idxStart, int idxExit);

  private:
    Map& map;
    std::vector<unsigned int> dist;
    std::vector<MapNode *> from;
    std::priority_queue<NodeInfo*, std::vector<NodeInfo*>, NodeCmp> nodeInfo;
    int minDist;
};

DijkstraExplorer::DijkstraExplorer(Map &map_): minDist(0), map(map_)
{
    int nodeCnt = map.getNodeCount();
    dist.resize(nodeCnt);
    from.resize(nodeCnt);
}

void DijkstraExplorer::findMinPath(MapNode* pStart, MapNode* pExit)
{
    // Initialize dist and from array
    MapNode* pNode;
    for (int i = 0; i < dist.size(); i++)
    {
        pNode = map.getNodeByIdx(i);
        if (pNode == pStart)
            dist[i] = 0;
        else
            dist[i] = 0xFFFFFFFF;
        from[i] = NULL;
        
        nodeInfo.push(&NodeInfo(pNode, i));
    }
    
    std::list<MapNode*>::iterator iter;
    NodeInfo* pNodeInfo;
    while (!nodeInfo.empty())
    {
        pNodeInfo = nodeInfo.top(); nodeInfo.pop();
        iter = pNodeInfo
    }
    
}

void DijkstraExplorer::findMinPath(int idxStart, int idxExit)
{
    MapNode* pStart = map.getNodeByIdx(idxStart);
    MapNode* pExit = map.getNodeByIdx(idxExit);

    findMinPath(pStart, pExit);
}