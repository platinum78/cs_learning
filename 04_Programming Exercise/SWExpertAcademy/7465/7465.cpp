#include <iostream>
#include <vector>
#include <cstdio>

void changeGroup(std::vector<int> &people, int src, int dest)
{
    for (int i = 0; i < people.size(); i++)
        if (people[i] == src)
            people[i] = dest;
}

int countZeros(std::vector<int> &people)
{
    int zeroCnt = 0;
    for (int i = 0; i < people.size(); i++)
        if (people[i] == 0)
            ++zeroCnt;
    return zeroCnt;
}

int main(void)
{   
    freopen("input.txt", "r", stdin);
    int tcCnt;
    int person1, person2;
    int population, pairs;
    int groups, maxGroup;
    std::cin >> tcCnt;
    std::vector<int> people;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        // Initialize pair vector.
        fscanf(stdin, "%d %d", &population, &pairs);
        people.resize(population + 1);
        for (int i = 0; i < people.size(); i++)
            people[i] = 0;
        
        groups = 0; maxGroup = 0;
        for (int i = 0; i < pairs; i++)
        {
            fscanf(stdin, "%d %d", &person1, &person2);
            if (people[person1] == 0 && people[person2] == 0)
            {
                ++groups; ++maxGroup;
                people[person1] = people[person2] = maxGroup;
            }
            else if (people[person1] == 0 && people[person2] != 0)
            {
                people[person1] = people[person2];
            }
            else if (people[person1] != 0 && people[person2] == 0)
            {
                people[person2] = people[person1];
            }
            else
            {
                if (people[person1] != people[person2])
                {
                    if (people[person1] < people[person2])
                        changeGroup(people, people[person2], people[person1]);
                    else
                        changeGroup(people, people[person1], people[person2]);
                    --groups;
                }
            }
        }

        fprintf(stdout, "#%d %d \n", tc, groups + countZeros(people) - 1);
    }
}