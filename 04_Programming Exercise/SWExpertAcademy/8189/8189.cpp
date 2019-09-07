#include <stdio.h>

class Queue
{
public:
    Queue();
    void push(int val);
    int front();
    void pop();
    int size();
    void init();

private:
    int front_;
    int rear_;
    int arr_[1001];
};

Queue::Queue() : front_(0), rear_(-1) {}

void Queue::push(int val)
{
    arr_[++rear_] = val;
}

int Queue::front()
{
    return arr_[front_];
}

void Queue::pop()
{
    ++front_;
}

int Queue::size()
{
    return rear_ - front_ + 1;
}

void Queue::init()
{
    front_ = 0;
    rear_ = -1;
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    
    int tcCnt;
    int N, A, B, t, n;
    Queue letterQ;
    Queue inboxQ;
    scanf("%d", &tcCnt);

    for (int tc = 1; tc <= tcCnt; tc++)
    {
        scanf("%d %d %d", &N, &A, &B);
        letterQ.init();
        inboxQ.init();
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &t);
            letterQ.push(t);
        }
        if (A == 1)
        {
            printf("#%d ", tc);
            while (letterQ.size())
            {
                printf("%d ", letterQ.front());
                letterQ.pop();
            }
            printf("\n");
            continue;
        }

        printf("#%d ", tc);
        inboxQ.push(letterQ.front()); letterQ.pop();
        t = inboxQ.front();
        while (1)
        {
            if (letterQ.front() == t)
            {
                inboxQ.push(letterQ.front());
                letterQ.pop();
            }

            if (inboxQ.front() == t - B || inboxQ.size() >= A)
            {
                n = (inboxQ.size() + 1) / 2;
                for (int i = 0; i < n; i++)
                {
                    inboxQ.pop();
                    printf("%d ", t);
                }
            }

            if (letterQ.size() == 0 && inboxQ.size() == 0)
                break;
            
            t++;
        }
        printf("\n");
    }
}