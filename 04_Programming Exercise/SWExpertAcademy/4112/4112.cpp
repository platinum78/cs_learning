// SWExpertAcademy Problem #4112
// Start: 16 FEB 2019, 15:57
// Finish: 16 FEB 2019, 16:35

#include <iostream>
#include <cmath>

typedef struct Coordinate_
{
    int numFloor;
    int position;
} Coordinate;

Coordinate findCoord(int num)
{
    Coordinate pos;
    int floorEnd = 0;
    int numFloor = 0;

    while (true)
    {
        floorEnd += ++numFloor;
        if (num <= floorEnd)
            break;
    }
     
    pos.numFloor = numFloor;
    pos.position = numFloor - (floorEnd - num);

    return pos;
}

int minTime(Coordinate origin, Coordinate destination)
{
    int floorDiff = destination.numFloor - origin.numFloor;
    int posDiff = destination.position - origin.position;

    if (floorDiff < 0)
    {
        if (posDiff < floorDiff)
            return -posDiff;
        else if (posDiff <= 0)
            return -floorDiff;
        else
            return -floorDiff + posDiff;
    }
    else if (0 < floorDiff)
    {
        if (floorDiff < posDiff)
            return posDiff;
        else if (0 <= posDiff)
            return floorDiff;
        else
            return floorDiff - posDiff;
    }
    else
    {
        return abs(posDiff);
    }
}

int main(void)
{
    Coordinate origin, destination;
    int tcCnt;
    int numBuf;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> numBuf;
        origin = findCoord(numBuf);
        std::cin >> numBuf;
        destination = findCoord(numBuf);

        std::cout << "#" << tc << " " << minTime(origin, destination) << std::endl;
    }

    return 0;
}