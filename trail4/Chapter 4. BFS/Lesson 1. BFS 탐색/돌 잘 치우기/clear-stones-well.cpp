#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, k, m;
int best = 0;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<pair<int, int>> point;

void pushing(int row, int col, vector<vector<int>> &visit, vector<vector<int>> &v, queue<pair<int, int>> &q, int &count)
{
    if (row == n || row == -1 || col == n || col == -1)
    {
        return;
    }
    if (visit[row][col] == 1 || v[row][col] == 1)
    {
        return;
    }
    q.push({row, col});
    visit[row][col] = 1;
    count++;
}

void finding(vector<vector<int>> &v, vector<pair<int, int>> &stone, vector<int> &select)
{
    vector<vector<int>> visit(n, vector<int>(n, 0));
    int count = 0;
    for (int i = 0; i < select.size(); i++)
    {
        v[stone[select[i]].first][stone[select[i]].second] = 0;
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < point.size(); i++)
    {
        q.push(point[i]);
        visit[point[i].first][point[i].second] = 1;
        count++;
    }
    int row, col;
    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];
            pushing(nr, nc, visit, v, q, count);
        }
        q.pop();
    }
    for (int i = 0; i < select.size(); i++)
    {
        v[stone[select[i]].first][stone[select[i]].second] = 1;
    }
    best = max(count, best);
}

void selecting(vector<int> &select, int start, vector<pair<int, int>> &stone, vector<vector<int>> &v)
{
    if (select.size() == m)
    {
        finding(v, stone, select);
        return;
    }
    if (start == stone.size())
    {
        return;
    }
    select.push_back(start);
    selecting(select, start + 1, stone, v);
    select.pop_back();
    if (m - select.size() < stone.size() - start)
    {
        selecting(select, start + 1, stone, v);
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &m);
    vector<vector<int>> v(n, vector<int>(n));
    vector<pair<int, int>> stone;
    vector<int> select;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 1)
            {
                stone.push_back({i, j});
            }
        }
    }
    int r, c;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &r, &c);
        r--;
        c--;
        point.push_back({r, c});
    }
    selecting(select, 0, stone, v);
    printf("%d", best);
    return 0;
}