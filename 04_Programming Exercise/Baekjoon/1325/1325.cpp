#include <vector>
#include <list>
#include <stack>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct hackable
{
    int computer;
    int hackableCnt;
    bool operator<(hackable &h)
    {
        if (hackableCnt > h.hackableCnt)
            return true;
        else if (hackableCnt == h.hackableCnt)
        {
            if (computer < h.computer)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};

int countHackables(std::vector< std::list<int> > &computers, int start_idx)
{
    std::stack<int> active;
    std::vector<bool> visited(computers.size() + 1, false);
    std::list<int>::iterator iter;
    int v;
    int hackable = 0;

    active.push(start_idx);
    
    while (!active.empty())
    {
        do
        {
            v = active.top();
            active.pop();
        } while (visited[v]);
        ++hackable;

        visited[v] = false;
        for (iter = computers[v].begin(); iter != computers[v].end(); iter++)
            active.push(*iter);
    }

    visited.resize(0);
    return hackable;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    int pcCnt, pairCnt;
    int pc1, pc2;
    std::vector< std::list<int> > computers;
    std::vector<hackable> hackableCnt;
    scanf("%d %d", &pcCnt, &pairCnt);

    computers.resize(pcCnt + 1);
    hackableCnt.resize(pcCnt);
    for (int i = 0; i < computers.size(); i++)
        computers[i].resize(0);

    for (int i = 0; i < pairCnt; i++)
    {
        scanf("%d %d", &pc2, &pc1);
        computers[pc1].push_back(pc2);
    }

    for (int i = 1; i <= pcCnt; i++)
    {
        hackableCnt[i - 1].computer = i;
        hackableCnt[i - 1].hackableCnt = countHackables(computers, i);
    }

    std::sort(hackableCnt.begin(), hackableCnt.end());
    int maxHackable = hackableCnt[0].hackableCnt;
    for (int i = 0; i < hackableCnt.size() && hackableCnt[i].hackableCnt == maxHackable; i++)
        printf("%d ", hackableCnt[i].computer);
    printf("\n");

    return 0;
}