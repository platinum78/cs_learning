#include <iostream>
#include <vector>

void drawOneTick(int tickLength, int tickLabel=-1)
{
    for (int i = 0; i < tickLength; i++)
        std::cout << "-";
    if (tickLabel >= 0)
        std::cout << " " << tickLabel;
    std::cout << '\n';
}

void drawTicks(int tickLength)
{
    if (tickLength > 0)
    {
        drawTicks(tickLength - 1);
        drawOneTick(tickLength);
    }
}