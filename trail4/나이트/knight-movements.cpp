#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int mr[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int mc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

void pushing(queue<pair<int, int>> &q, vector<vector<int>> &visit, int row, int col)
{
    if (row <= -1 || row >= n || col <= -1 || col >= n)
    {
        return;
    }
    if (visit[row][col] == 1)
    {
        return;
    }
    q.push({row, col});
    visit[row][col] = 1;
}
int main()
{
    scanf("%d", &n);
    vector<vector<int>> visit(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    int count = 0;
    int sr, sc;
    int dr, dc;
    scanf("%d %d %d %d", &sr, &sc, &dr, &dc);
    sr--;
    sc--;
    q.push({sr, sc });
    visit[sr][sc ] = 1;
    dr--;
    dc--;
    bool flag = false;

    while (!q.empty())
    {
        if (sr == dr && sc == dc)
        {
            count = 0;
            flag = true;
            break;
        }
        int size = q.size();
        int nr, nc;
        count++;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                nr = q.front().first + mr[j];
                nc = q.front().second + mc[j];
                pushing(q, visit, nr, nc);
                if (nr == dr && nc == dc)
                {
                    flag = true;
                    break;
                }
            }
            q.pop();

            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        count = -1;
    }
    printf("%d", count);

    return 0;
}