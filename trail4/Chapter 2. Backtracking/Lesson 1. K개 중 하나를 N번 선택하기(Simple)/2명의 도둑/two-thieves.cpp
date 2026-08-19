#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

int c, n, m, answer = 0;

void find(vector<vector<int>> &s, int x, int y, int x2, int y2)
{
    if (y >= n - 1 && x >= s[0].size()-m)
    {
        return;
    }
    if ((x >= s[0].size()-m && y == y2) || x2 >= s[0].size())
    {
        if (y2 == n - 1)
        {
            return;
        }
        find(s, x, y, 0, y2 + 1);
        return;
    }
    if(x2-x<m && y==y2)
    {
        find(s,x,y,x2+1,y2);
        return;
    }
    int temp = s[y][x] + s[y2][x2];
    answer = max(answer, temp);
    find(s,x,y,x2+1,y2);
}

void cal(vector<vector<int>> &v, int x, int y, vector<int> q, int &result)
{
    int sum = 0;
    int a = 0;
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        sum += q[i];
    }
    if (sum <= c)
    {
        for (int i = 0; i < size; i++)
        {
            a += q[i] * q[i];
        }
        result = max(result, a);
        return;
    }
    if (size != 1)
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            int temp = q[i];
            swap(q[i], q[size - 1]);
            q.pop_back();
            cal(v, x, y, q, result);
            q.push_back(temp);
            swap(q[i], q[size - 1]);
        }
    }
}

void next_comb(vector<int> &q, int x, int y, vector<vector<int>> &v)
{
    int size = q.size();
    if ((x + m) == n && y < n - 1)
    {
        y++;
        x = 0;
        for (int i = 0; i < size; i++)
        {
            q.pop_back();
        }
        for (int i = 0; i < m; i++)
        {
            q.push_back(v[y][i]);
        }
        return;
    }
    queue<int> t;
    for (int i = 0; i < m; i++)
    {
        t.push(q[i]);
    }
    t.pop();
    t.push(v[y][x + m]);
    for (int i = 0; i < size; i++)
    {
        q.pop_back();
    }
    while (!t.empty())
    {
        q.push_back(t.front());
        t.pop();
    }
}

int main()
{
    int result = 0;
    scanf("%d %d %d", &n, &m, &c);
    vector<vector<int>> v(n, vector<int>(n));
    vector<int> q(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        q[i] = v[0][i];
    }
    vector<vector<int>> s(n, vector<int>(n - m + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - m + 1); j++)
        {
            cal(v, i, j, q, result);
            s[i][j] = result;
            next_comb(q, j, i, v);
            result = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-m+1);j++)
        {
            find(s,j,i,j,i);
        }
    }
    printf("%d",answer);
    return 0;
}