#include <iostream>
#include <vector>
#include <cstdio>

typedef struct ScoreSheet_
{
    std::vector<char> answers;
    int score;
} ScoreSheet;

ScoreSheet* maxScore(ScoreSheet* score1, ScoreSheet* score2, ScoreSheet* score3)
{
    if (score1->score >= score2->score && score1->score >= score3->score)
        return score1;
    if (score2->score >= score1->score && score2->score >= score3->score)
        return score2;
    if (score3->score >= score1->score && score3->score >= score2->score)
        return score3;
    return NULL;
}

ScoreSheet* minScore(ScoreSheet* score1, ScoreSheet* score2, ScoreSheet* score3)
{
    if (score1->score <= score2->score && score1->score <= score3->score)
        return score1;
    if (score2->score <= score1->score && score2->score <= score3->score)
        return score2;
    if (score3->score <= score1->score && score3->score <= score2->score)
        return score3;
    return NULL;
}

int happyTest(ScoreSheet* mwAnswer, ScoreSheet* jwAnswer, ScoreSheet* kwAnswer)
{
    int questionCnt = mwAnswer->score;
    char answer;
    ScoreSheet* pMaxScore;
    ScoreSheet* pMinScore;

    for (int q = 0; q < questionCnt; q++)
    {
        pMaxScore = maxScore(mwAnswer, jwAnswer, kwAnswer);
        pMinScore = minScore(mwAnswer, jwAnswer, kwAnswer);
        answer = pMinScore->answers[q];

        if (mwAnswer->answers[q] != answer)
            --mwAnswer->score;
        if (jwAnswer->answers[q] != answer)
            --jwAnswer->score;
        if (kwAnswer->answers[q] != answer)
            --kwAnswer->score;
        
        std::cout << mwAnswer->score << " " << jwAnswer->score << " " << kwAnswer->score << std::endl;
    }

    pMinScore = minScore(mwAnswer, jwAnswer, kwAnswer);
    return pMinScore->score;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    ScoreSheet mwAnswer;
    ScoreSheet jwAnswer;
    ScoreSheet kwAnswer;
    int tcCnt, questionCnt;
    std::cin >> tcCnt;

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        std::cin >> questionCnt;
        mwAnswer.answers.resize(questionCnt);
        jwAnswer.answers.resize(questionCnt);
        kwAnswer.answers.resize(questionCnt);
        mwAnswer.score = jwAnswer.score = kwAnswer.score = questionCnt;

        for (int a = 0; a < questionCnt; a++)
            std::cin >> mwAnswer.answers[a];
        for (int a = 0; a < questionCnt; a++)
            std::cin >> jwAnswer.answers[a];
        for (int a = 0; a < questionCnt; a++)
            std::cin >> kwAnswer.answers[a];
        
        std::cout << "#" << tc << " " << happyTest(&mwAnswer, &jwAnswer, &kwAnswer) << std::endl;
    }
}