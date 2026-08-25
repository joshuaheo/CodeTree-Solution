#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int tim = 0;
int cnt = 0;
int result;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
void pushing(int row, int col, vector<vector<int>> &visit, queue<pair<int, int>> &q, queue<pair<int, int>> &f, vector<vector<int>> &v)
{
    if (row == -1 || row == n || col == -1 || col == m)
    {
        return;
    }
    if (v[row][col] == 1)
    {
        return;
    }
    if (visit[row][col] == 1)
    {
        return;
    }
    q.push({row, col});
    f.push({row, col});
    visit[row][col] = 1;
}

void finding(vector<vector<int>> &v)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> f;
    vector<vector<int>> visit(n, vector<int>(m, 0));
    f.push({0, 0});
    q.push({0, 0});
    while (!f.empty())
    {
        for (int i = 0; i < 4; i++)
        {
            int tempr = f.front().first + dr[i], tempc = f.front().second + dc[i];
            pushing(tempr, tempc, visit, q, f, v);
        }
        f.pop();
    }
    while (1)
    {
        result = cnt;
        tim++;
        f = q;
        q = queue<pair<int, int>>();
        while (!f.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                int tempr = f.front().first + dr[i], tempc = f.front().second + dc[i];
                if (tempr == -1 || tempr == n || tempc == -1 || tempc == m)
                {
                    continue;
                }
                if (v[tempr][tempc] == 1)
                {
                    v[tempr][tempc] = 0;
                    q.push({tempr, tempc});
                    visit[tempr][tempc] = 1;
                    cnt--;
                }
            }
            f.pop();
        }
        f = q;
        while (!f.empty())
        {
            for (int i = 0; i < 4; i++)
            {
                int tempr = f.front().first + dr[i], tempc = f.front().second + dc[i];
                pushing(tempr, tempc, visit, q, f, v);
            }
            f.pop();
        }
        if (cnt == 0)
        {
            break;
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 1)
            {
                cnt++;
            }
        }
    }
    finding(v);
    printf("%d %d", tim, result);
    return 0;
}