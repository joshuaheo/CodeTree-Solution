#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, h, m;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void pushing(vector<vector<int>> &v, vector<vector<int>> &visit, queue<tuple<int, int, int>> &q, int row, int col)
{
    auto [a, b, c] = q.front();
    if (row < 0 || row >= n || col < 0 || col >= n)
    {
        return;
    }
    if (visit[row][col] != -1)
    {
        return;
    }
    q.push({row, col, c + 1});
    visit[row][col] = c + 1;
}

int main()
{
    scanf("%d %d %d", &n, &h, &m);
    vector<vector<int>> v(n, vector<int>(n));
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visit(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 1)
            {
                visit[i][j] = -2;
            }
            if (v[i][j] == 3)
            {
                q.push({i, j, 0});
            }
        }
    }
    while (!q.empty())
    {
        auto [row, col, count] = q.front();
        for (int i = 0; i < 4; i++)
        {
            int nr=row+dr[i];
            int nc=col+dc[i];
            pushing(v, visit, q,nr,nc);
        }
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]!=2)
            {
                visit[i][j]=0;
            }
            printf("%d ",visit[i][j]);
        }
        printf("\n");
    }
    return 0;
}