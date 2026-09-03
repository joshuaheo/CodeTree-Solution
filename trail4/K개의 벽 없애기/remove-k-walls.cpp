#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <tuple>
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int n, k;
void pushing(vector<vector<int>> &v, vector<vector<vector<int>>> &visit, queue<tuple<int, int, int>> &q, int row, int col, int broken)
{
    if (row < 0 || row >= n || col < 0 || col >= n)
    {
        return;
    }
    if (visit[row][col][broken] == 1)
    {
        return;
    }
    if(v[row][col]==1)
    {
        if(broken==k)
        {
            return;
        }
        else{
            broken++;
        }
    }
    q.push({row, col, broken});
    visit[row][col][broken] = 1;
}
int main()
{
    scanf("%d %d", &n, &k);
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<vector<int>>> visit(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    int sr, sc, nr, nc;
    scanf("%d %d", &sr, &sc);
    scanf("%d %d", &nr, &nc);
    sr--;
    sc--;
    nr--;
    nc--;
    q.push({sr, sc, 0});
    visit[sr][sc][0] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int size = q.size();
        while (size)
        {
            auto [row, col, broken] = q.front();
            if (row == nr && col == nc)
            {
                printf("%d", cnt);
                return 0;
            }
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int a = row + dr[i];
                int b = col + dc[i];
                pushing(v,visit,q,a,b,broken);
            }
            size--;
        }
        cnt++;
    }
    printf("-1");
    return 0;
}