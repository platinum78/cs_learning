#include <iostream>
#include <vector>
#include <cstdio>

int conv2D(std::vector< std::vector<char> >& largeMap, std::vector< std::vector<char> >& smallMap)
{
    if (largeMap.size() < smallMap.size())
        return 0;
    if (largeMap[0].size() < smallMap[0].size())
        return 0;
    int largeHeight = largeMap.size(), largeWidth = largeMap[0].size();
    int smallHeight = smallMap.size(), smallWidth = smallMap[0].size();
    int maxHeightPivot = largeHeight - smallHeight;
    int maxWidthPivot = largeWidth - smallWidth;
    bool isIdentical;
    int convCnt = 0;

    for (int H = 0; H <= maxHeightPivot; H++)
    {
        for (int W = 0; W <= maxWidthPivot; W++)
        {
            isIdentical = true;
            for (int h = 0; h < smallHeight; h++)
            {
                for (int w = 0; w < smallWidth; w++)
                {
                    if (smallMap[h][w] != largeMap[H+h][W+w])
                    {
                        isIdentical = false;
                        break;
                    }
                }

                if (!isIdentical)
                    break;
            }
            if (isIdentical)
                ++convCnt;
        }
    }

    return convCnt;
}

int main(void)
{
    int tcCnt;
    int ekHeight, ekWidth, tHeight, tWidth;
    std::vector< std::vector<char> > ekPaint;
    std::vector< std::vector<char> > tPaint;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> ekHeight >> ekWidth >> tHeight >> tWidth;
        
        ekPaint.resize(ekHeight);
        for (int i = 0; i < ekHeight; i++)
        {
            ekPaint[i].resize(ekWidth);
            for (int j = 0; j < ekWidth; j++)
                std::cin >> ekPaint[i][j];
        }

        tPaint.resize(tHeight);
        for (int i = 0; i < tHeight; i++)
        {
            tPaint[i].resize(tWidth);
            for (int j = 0; j < tWidth; j++)
                std::cin >> tPaint[i][j];
        }

        std::cout << "#" << tc << " " << conv2D(tPaint, ekPaint) << std::endl;
    }
        
}