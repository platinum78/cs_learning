#include <cstdio>
#include <cmath>
#include <vector>
#define MAX_ERROR 1e-12
#define MIN_OFFSET 1e-5

double leftAttraction(std::vector<double> &points, std::vector<double> &mass, double pos)
{
    double totalForce = 0;

    for (int i = 0; i < points.size(); i++)
        if (points[i] < pos)
            totalForce += mass[i] / pow(points[i] - pos, 2);
    
    return totalForce;
}

double rightAttraction(std::vector<double> &points, std::vector<double> &mass, double pos)
{
    double totalForce = 0;

    for (int i = 0; i < points.size(); i++)
        if (points[i] > pos)
            totalForce += mass[i] / pow(points[i] - pos, 2);
    
    return totalForce;
}

double attractionForce(std::vector<double> &points, std::vector<double> &mass, double pos)
{
    return rightAttraction(points, mass, pos) - leftAttraction(points, mass, pos);
}

double findEqPoint_(std::vector<double> &points, std::vector<double> &mass, double left, double right)
{
    if (right - left < MAX_ERROR)
        return (left + right) / 2;

    double center = (left + right) / 2;
    double leftForce = attractionForce(points, mass, left);
    double rightForce = attractionForce(points, mass, right);
    double centerForce = attractionForce(points, mass, center);
    double eqPoint;

    // printf("%lf, %lf \n", leftForce, rightForce);

    if (centerForce < 0)
        eqPoint = findEqPoint_(points, mass, center, right);
    else
        eqPoint = findEqPoint_(points, mass, left, center);
    
    return eqPoint;
}

double findEqPoint(std::vector<double> &points, std::vector<double> &mass, double left, double right)
{
    return findEqPoint_(points, mass, left + MIN_OFFSET, right - MIN_OFFSET);
}

int main(void)
{
    freopen("input.txt", "r", stdin);

    int tcCnt, pointCnt;
    double left, right, eqPoint;
    std::vector<double> points;
    std::vector<double> mass;

    scanf("%d", &tcCnt);
    for (int tc = 1; tc <= tcCnt; tc++)
    {
        printf("#%d ", tc);
        scanf("%d", &pointCnt);
        points.resize(pointCnt);
        mass.resize(pointCnt);

        for (int i = 0; i < pointCnt; i++)
            scanf("%lf", &points[i]);
        
        for (int i = 0; i < pointCnt; i++)
            scanf("%lf", &mass[i]);

        for (int i = 0; i < pointCnt - 1; i++)
        {
            eqPoint = findEqPoint(points, mass, points[i], points[i + 1]);
            printf("%.10lf ", tc, eqPoint);
        }
        printf("\n");
    }
}