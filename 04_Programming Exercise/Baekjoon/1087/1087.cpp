#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

struct Mouse
{
    double px;
    double py;
    double vx;
    double vy;
};

Mouse *makeNewMouse(double px, double py, double vx, double vy)
{
    Mouse *pNewMouse;
    pNewMouse->px = px;
    pNewMouse->py = py;
    pNewMouse->vx = vx;
    pNewMouse->vy = vy;
    return pNewMouse;
}

struct Collision
{
    Mouse *prev_larger;
    Mouse *prev_smaller;
    double t;
    double val;

    bool operator<(Collision &c)
    {
        return (t < c.t);
    }
};

Collision *makeNewCollisionX(Mouse *m1, Mouse *m2)
{
    if (m1->vx == m2->vx)
        return NULL;
    else
    {
        double t = (m1->px - m2->px) / (m2->vx - m1->vx);
        double x = m1->px + m1->vx * t;
        Collision *pNewCollision = new Collision;
        if (m1->vx > m2->vx)
        {
            pNewCollision->prev_larger = m2;
            pNewCollision->prev_smaller = m1;
        }
        else
        {
            pNewCollision->prev_larger = m1;
            pNewCollision->prev_smaller = m2;
        }
        pNewCollision->t = t;
        pNewCollision->val = x;
        return pNewCollision;
    }
}

Collision *makeNewCollisionY(Mouse *m1, Mouse *m2)
{
    if (m1->vy == m2->vy)
        return NULL;
    else
    {
        double t = (m1->py - m2->py) / (m2->vy - m1->vy);
        double y= m1->py + m1->vy * t;
        Collision *pNewCollision = new Collision;
        if (m1->vy > m2->vy)
        {
            pNewCollision->prev_larger = m2;
            pNewCollision->prev_smaller = m1;
        }
        else
        {
            pNewCollision->prev_larger = m1;
            pNewCollision->prev_smaller = m2;
        }
        pNewCollision->t = t;
        pNewCollision->val = y;
        return pNewCollision;
    }
}

int main(void)
{
    int mouseCnt;
    std::vector<Mouse*> mice;
    std::list<Collision *> xCollision, yCollision;
    double px, py, vx, vy;
    Mouse *pNewMouse;
    std::cin >> mouseCnt;

    mice.resize(mouseCnt);
    for (int i = 0; i < mouseCnt; i++)
    {
        pNewMouse = new Mouse;
        std::cin >> px >> py >> vx >> vy;
        mice[i] = makeNewMouse(px, py, vx, vy);
    }

    Collision *pNewCollision;
    for (int i = 0; i < mice.size() - 1; i++)
    {
        for (int j = i; j < mice.size(); j++)
        {
            pNewCollision = makeNewCollisionX(mice[i], mice[j]);
            if (pNewCollision)
            {
                xCollision.push_back(pNewCollision);
                std::push_heap(xCollision.begin(), xCollision.end());
            }

            pNewCollision = makeNewCollisionX(mice[i], mice[j]);
            if (pNewCollision)
            {
                xCollision.push_back(pNewCollision);
                std::push_heap(xCollision.begin(), xCollision.end());
            }
        }
    }
}