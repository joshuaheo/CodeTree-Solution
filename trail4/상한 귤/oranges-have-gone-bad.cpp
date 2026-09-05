#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
void pushing(vector<vector<int>> &v, vector<vector<int>> &visit, queue<pair<int, int>> &q, int row, int col, int cnt)
{
    if (row < 0 || row >= n || col < 0 || col >= n)
    {
        return;
    }
    if (v[row][col] == 0)
    {
        return;
    }
    if (visit[row][col] != -2)
    {
        return;
    }
    q.push({row, col});
    visit[row][col] = cnt;
}
int main()
{
    scanf("%d %d", &n, &k);
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> visit(n, vector<int>(n, -2));
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 0)
            {
                visit[i][j] = -1;
            }
            if (v[i][j] == 2)
            {
                q.push({i, j});
                visit[i][j] = cnt;
            }
        }
    }
    while (!q.empty())
    {
        int size = q.size();
        cnt++;
        while (size)
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int row = r + dr[i];
                int col = c + dc[i];
                pushing(v, visit, q, row, col, cnt);
            }
            size--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", visit[i][j]);
        }
        printf("\n");
    }
    return 0;
}