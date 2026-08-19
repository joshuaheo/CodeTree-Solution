#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, m;
void pushing(int x, int y, queue<pair<int, int>> &q, vector<vector<int>> &visit, vector<vector<int>> &v)
{
    if (x < 0 || y < 0 || x > m - 1 || y > n - 1)
    {
        return;
    }
    if (v[y][x] == 0)
    {
        return;
    }
    if (visit[y][x] == 1)
    {
        return;
    }
    q.push({y, x});
    visit[y][x] = 1;
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
        }
    }
    vector<vector<int>> visit(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({0, 0});
    int x, y, temp = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    visit[0][0] = 1;
    while (!q.empty())
    {
        x = q.front().second;
        y = q.front().first;
        if (x == m - 1 && y == n - 1)
        {
            temp = 1;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            pushing(x + dx[i], y + dy[i], q, visit,v);
        }
        q.pop();
    }
    printf("%d", temp);

    return 0;
}