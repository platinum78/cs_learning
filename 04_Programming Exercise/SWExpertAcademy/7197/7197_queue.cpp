#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#define DIR_EAST 0
#define DIR_NORTH 1
#define DIR_WEST 2
#define DIR_SOUTH 3
#define DIR_CONSTRAIN(X) (X % 4)

#define REFLECT_CCW 1
#define REFLECT_NONE 0
#define REFLECT_CW -1

typedef struct Point_
{
    int x;
    int y;
} Point;

typedef struct LightRay_
{
    int direction;
    Point initPos;
    Point currentPos;
    int reflectCnt;
} LightRay;

bool proceedUntilMirror(LightRay &ray, std::vector<Point> &mirrorList)
{
    int minDist = 0x7FFFFFFF, dist;
    if (ray.direction == DIR_EAST)
    {
        for (int i = 0; i < mirrorList.size(); i++)
        {
            if (mirrorList[i].y == ray.currentPos.y)
            {
                dist = mirrorList[i].x - ray.currentPos.x;
                if (dist > 0 && dist < minDist)
                    minDist = dist;
            }
        }
        ray.currentPos.x += minDist;
    }
    else if (ray.direction == DIR_NORTH)
    {
        for (int i = 0; i < mirrorList.size(); i++)
        {
            if (mirrorList[i].x == ray.currentPos.x)
            {
                dist = mirrorList[i].y - ray.currentPos.y;
                if (dist > 0 && dist < minDist)
                    minDist = dist;
            }
        }
        ray.currentPos.y += minDist;
    }
    else if (ray.direction == DIR_WEST)
    {
        for (int i = 0; i < mirrorList.size(); i++)
        {
            if (mirrorList[i].y == ray.currentPos.y)
            {
                dist = ray.currentPos.x - mirrorList[i].x;
                if (dist > 0 && dist < minDist)
                    minDist = dist;
            }
        }
        ray.currentPos.x -= minDist;
    }
    else
    {
        for (int i = 0; i < mirrorList.size(); i++)
        {
            if (mirrorList[i].x == ray.currentPos.x)
            {
                dist = ray.currentPos.y - mirrorList[i].y;
                if (dist > 0 && dist < minDist)
                    minDist = dist;
            }
        }
        ray.currentPos.y -= minDist;
    }
    
    if (minDist != 0x7FFFFFFF)
        return true;
    else
        return false;
}

int minReflection(Point &initPos, std::vector<Point> mirrorList)
{
    std::queue<LightRay> activeRays;
    int minReflect = 0x7FFFFFFF;
    LightRay ray;

    activeRays.push((LightRay){ DIR_EAST, initPos, initPos, 0 });
    activeRays.push((LightRay){ DIR_NORTH, initPos, initPos, 0 });
    activeRays.push((LightRay){ DIR_WEST, initPos, initPos, 0 });
    activeRays.push((LightRay){ DIR_SOUTH, initPos, initPos, 0 });

    while (!activeRays.empty())
    {
        ray = activeRays.front();
        if (proceedUntilMirror(ray, mirrorList))
        {
            activeRays.push((LightRay){ DIR_CONSTRAIN(ray.direction + REFLECT_CCW), ray.currentPos, ray.currentPos, ray.reflectCnt + 1 });
            activeRays.push((LightRay){ DIR_CONSTRAIN(ray.direction + REFLECT_NONE), ray.currentPos, ray.currentPos, ray.reflectCnt + 1 });
            activeRays.push((LightRay){ DIR_CONSTRAIN(ray.direction + REFLECT_CW), ray.currentPos, ray.currentPos, ray.reflectCnt + 1 });
        }

    }
}