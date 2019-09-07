#include <iostream>
#include <string>
#include <map>
#include <queue>


int main(void)
{
    freopen("input.txt", "r", stdin);

    std::map<std::string, int> nameTable;
    std::string name1, name2;
    int id1, id2;

    std::vector<std::vector<bool> > cxnMat(100, std::vector<bool>(100, false));
    std::vector<int> team;

    int components = 0;
    bool disconnected = false;
    std::queue<int> open;
    int tcCnt, relCnt, manCnt = 0;
    std::cin >> tcCnt;
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> relCnt;

        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cxnMat[i][j] = false;

        manCnt = 0;
        for (int i = 0; i < relCnt; i++)
        {
            std::cin >> name1 >> name2;
            if (nameTable.count(name1) == 0)
                nameTable[name1] = manCnt++;
            if (nameTable.count(name2) == 0)
                nameTable[name2] = manCnt++;
            id1 = nameTable[name1];
            id2 = nameTable[name2];
            cxnMat[id1][id2] = cxnMat[id2][id1] = true;
        }

        team.resize(manCnt, 0);
        team[0] = 1;
        for (int i = 0; i < manCnt; i++)
        {
            for (int j = 0; j < manCnt; j++)
            {
                
            }
        }

        if (depart)
            printf("#%d Yes \n", tc);
        else
            printf("#%d No \n", tc);
    }
}