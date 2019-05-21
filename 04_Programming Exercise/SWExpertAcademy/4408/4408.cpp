#include <cstdio>
#include <vector>
#include <list>

struct Interval
{
    int begin;
    int end;
};

class MinTimeFinder
{
    public:
    MinTimeFinder();

    public:
    int FindMinTime();

    private:
    std::vector< std::list<int> > rooms_;    // Size 400
    std::vector<int> min_times_;             // Size 200
};

MinTimeFinder::MinTimeFinder()
{
    rooms_.resize(400);
    min_times_.resize(200);
    for (int i = 0; i < min_times_.size(); i++)
        min_times_[i] = 0x7FFFFFFF;
}

int main(void)
{

}