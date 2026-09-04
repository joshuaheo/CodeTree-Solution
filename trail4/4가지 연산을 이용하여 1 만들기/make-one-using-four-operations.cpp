#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n;
bool flag = false;
void pushing(queue<int> &q, vector<int> &visit, int num)
{
    if (num < 1 || num > 1000000)
    {
        return;
    }
    if (visit[num] == 1)
    {
        return;
    }
    if (num == 1)
    {
        flag = true;
        return;
    }
    q.push(num);
    visit[num] = 1;
}
void finding(int num, queue<int> &q, vector<int> &visit)
{
    if (num % 2 == 0 && num % 3 == 0)
    {
        pushing(q, visit, num / 2);
        pushing(q, visit, num / 3);
    }
    else if (num % 2 == 0)
    {
        if ((num + 1) % 3 == 0)
        {
            pushing(q, visit, num + 1);
        }
        if ((num - 1) % 3 == 0)
        {
            pushing(q, visit, num - 1);
        }
        pushing(q, visit, num / 2);
    }
    else if (num % 3 == 0)
    {
        if ((num + 1) % 2 == 0)
        {
            pushing(q, visit, num + 1);
        }
        if ((num - 1) % 2 == 0)
        {
            pushing(q, visit, num - 1);
        }
        pushing(q, visit, num / 3);
    }
    else
    {
        pushing(q, visit, num - 1);
        pushing(q, visit, num + 1);
    }
}

int main()
{
    scanf("%d", &n);
    vector<int> visit(1000001, 0);
    queue<int> q;
    if(n==1)
    {
        printf("0");
        return 0;
    }
    q.push(n);
    int cnt = 0;
    visit[n] = 1;
    while (!q.empty())
    {
        int size = q.size();
        cnt++;
        while (size)
        {
            int num = q.front();
            q.pop();
            finding(num, q, visit);
            if (flag)
            {
                printf("%d", cnt);
                return 0;
            }
            size--;
        }
    }

    return 0;
}