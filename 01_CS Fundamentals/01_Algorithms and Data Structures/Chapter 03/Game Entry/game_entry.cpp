#include <iostream>
#include <string>

class IndexOutOfBounds
{
  public:
    IndexOutOfBounds(std::string &msg) { errMsg = msg; };
    std::string getErrMsg() { return errMsg; };

  private:
    std::string errMsg;
};

class GameEntry
{
  public:
    GameEntry(const std::string &n = "", int s = 0);
    std::string getc() const;
    int getScore() const;

  private:
    std::string name;
    int score;
};

class Scores
{
  public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry &e);
    GameEntry remove(int i) throw(IndexOutOfBounds);

  private:
    int maxEntries;
    int numEntries;
    GameEntry *entries;
};

Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores()
{
    delete[] entries;
}

void Scores::add(const GameEntry &e)
{
    int newScore = e.getScore();
    if (numEntries == maxEntries)
    {
        if (newScore <= entries[maxEntries - 1].getScore())
            return;
    }
    else
        numEntries;

    int i = numEntries - 2;
    while (i >= 0 && newScore > entries[i].getScore())
    {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry Scores::remove(int i) throw(IndexOutOfBounds)
{
    if (i < 0 || i >= numEntries)
        throw IndexOutOfBounds(std::string("Invalid index."));
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++)
        entries[j - 1] = entries[j];
    numEntries--;
    return e;
}