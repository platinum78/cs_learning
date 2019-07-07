#include <cstdio>
#include <memory.h>
int tree[10001][3];     // index: self, 0: parent, 1: left child, 2: right child, 3: subtree size

bool treeInsert(int parent, int child)
{
    tree[child][0] = parent;
    if (tree[parent][1] == 0)
        tree[parent][1] = child;
    else if (tree[parent][2] == 0)
        tree[parent][2] = child;
    else
        return false;
    return true;
}

int getNodeDepth(int n)
{
    int depth = 1;
    while (n != 1)
    {
        n = tree[n][0];
        ++depth;
    }
    return depth;
}

int getSubtreeSize(int node)
{
    int size = 1;
    if (tree[node][1])
        size += getSubtreeSize(tree[node][1]);
    if (tree[node][2])
        size += getSubtreeSize(tree[node][2]);
    return size;
}

int findCommonAncestor(int n1_, int n2_)
{
    int n1 = n1_, n2 = n2_;
    int n1Depth = getNodeDepth(n1), n2Depth = getNodeDepth(n2);

    while (n1Depth > n2Depth)
    {
        n1 = tree[n1][0];
        n1Depth--;
    }
    while (n2Depth > n1Depth)
    {
        n2 = tree[n2][0];
        n2Depth--;
    }

    while (n1 != n2)
    {
        n1 = tree[n1][0];
        n2 = tree[n2][0];
    }
    return n1;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int tcCnt;
    int V, E, n1, n2;
    int parent, child, commonAncestor;
    
    scanf("%d", &tcCnt);
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        memset(tree, '\0', 10001 * 3 * sizeof(int));
        scanf("%d %d %d %d", &V, &E, &n1, &n2);
        for (int i = 0; i < E; i++)
        {
            scanf("%d %d", &parent, &child);
            if (!treeInsert(parent, child))
                printf("Invalid operation! \n");
        }

        commonAncestor = findCommonAncestor(n1, n2);
        printf("#%d %d %d \n", tc, commonAncestor, getSubtreeSize(commonAncestor));
    }
}