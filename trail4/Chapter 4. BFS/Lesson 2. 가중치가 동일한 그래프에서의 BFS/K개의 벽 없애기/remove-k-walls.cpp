#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int n, k;
vector<pair<int, int>> wall;
int result = -1;
int sr, sc, nr, nc;
void pushing(vector<vector<int>> &v, vector<vector<int>> &visit, queue<pair<int, int>> &q, int row, int col)
{
    if (row < 0 || row >= n || col < 0 || col >= n)
    {
        return;
    }
    if (visit[row][col] == 1)
    {
        return;
    }
    if (v[row][col] == 1)
    {
        return;
    }
    q.push({row, col});
    visit[row][col] = 1;
}
void solving(vector<vector<int>> &v)
{
    queue<pair<int, int>> q;
    vector<vector<int>> visit(n, vector<int>(n, 0));
    q.push({sr - 1, sc - 1});
    visit[sr - 1][sc - 1] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            if (row == nr - 1 && col == nc - 1)
            {
                result = cnt;
                return;
            }
            if (cnt == result)
            {
                return;
            }
            for (int i = 0; i < 4; i++)
            {
                int a = row + dr[i];
                int b = col + dc[i];
                pushing(v, visit, q, a, b);
            }
            size--;
        }
        cnt++;
    }
}
void deleting(int index, int count, vector<vector<int>> &v)
{
    if (count == k || index == wall.size())
    {
        solving(v);
        return;
    }
    v[wall[index].first][wall[index].second] = 0;
    deleting(index + 1, count + 1, v);
    v[wall[index].first][wall[index].second] = 1;
    deleting(index + 1, count, v);
}
int main()
{
    scanf("%d %d", &n, &k);
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 1)
            {
                wall.push_back({i, j});
            }
        }
    }
    scanf("%d %d", &sr, &sc);
    scanf("%d %d", &nr, &nc);
    deleting(0, 0, v);
    printf("%d", result);
    return 0;
}