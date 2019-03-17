#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
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

class LightRay
{
  public:
    LightRay(Point initPos_, int dir_, int reflect_cnt_);
    void reflect();
    bool proceedUntilMirror(std::vector<Point> &mirrorList);
    bool isInROI(Point topLeft, Point bottomRight);

  public:
    LightRay *getLeft() { return reflectLeft; }
    LightRay *getNone() { return reflectNone; }
    LightRay *getRight() { return reflectRight; }
    LightRay *getPrevious() { return previous; }

  public:
    int getReflectionCnt() { return reflectCnt; }
    int getDirection() { return dir; }
    Point getFinalPos() { return finalPos; }

  private:
    Point initPos, finalPos;
    LightRay *previous, *reflectLeft, *reflectNone, *reflectRight;
    int dir, reflectCnt;
    bool isActive;
};

LightRay::LightRay(Point initPos_, int dir_, int reflect_cnt_)
    : initPos(initPos_), finalPos(initPos_), dir(dir_), isActive(true),
      reflectLeft(NULL), reflectNone(NULL), reflectRight(NULL), reflectCnt(reflect_cnt_)
{
    // Constructor
}

bool LightRay::proceedUntilMirror(std::vector<Point> &mirrorList)
{
}

int minReflect(Point initPos, std::vector<Point> mirrorList)
{
    std::list<LightRay *> activeRays;
    std::list<LightRay *>::iterator iter, iterBegin, iterEnd;
    bool mirrorAvailable;
    LightRay *pRay;
    Point finalPos;
    int dir;

    activeRays.push_back(&LightRay(initPos, DIR_EAST, 0));
    activeRays.push_back(&LightRay(initPos, DIR_NORTH, 0));
    activeRays.push_back(&LightRay(initPos, DIR_WEST, 0));
    activeRays.push_back(&LightRay(initPos, DIR_SOUTH, 0));

    while (!activeRays.empty())
    {
        iterBegin = activeRays.begin();
        iterEnd = activeRays.end();

        iter = iterBegin;
        while (iter != iterEnd)
        {
            if ((*iterBegin)->proceedUntilMirror(mirrorList))
            {
                pRay = *iter;
                activeRays.push_back(pRay->getLeft());
                activeRays.push_back(pRay->getNone());
                activeRays.push_back(pRay->getRight());
                activeRays.erase(iter);
                continue;
            }
        }
    }
}