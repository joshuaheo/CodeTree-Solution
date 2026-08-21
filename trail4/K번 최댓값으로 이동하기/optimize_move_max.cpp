#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, f;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void pushing(vector<vector<int>> &v, int tempr, int tempc, vector<vector<int>> &visit, queue<pair<int, int>> &q, int i, int &best, int& bestr, int& bestc)
{
    if (visit[tempr][tempc] == i)
    {
        return;
    }
    q.push({tempr, tempc});
    if (best < v[tempr][tempc])
    {
        best = v[tempr][tempc];
        bestr = tempr;
        bestc = tempc;
    }
    else if (best == v[tempr][tempc])
    {
        if (bestr == tempr)
        {
            if (tempc < bestc)
            {
                bestc = tempc;
            }
        }
        else if (tempr < bestr)
        {
            bestr = tempr;
            bestc = tempc;
        }
    }
    visit[tempr][tempc] = i;
}

void finding(int &row, int &col, vector<vector<int>> &v, vector<vector<int>> &visit)
{
    queue<pair<int, int>> q;
    int nextr, nextc;
    int bestr = row, bestc = col;
    for (int i = 0; i < f; i++)
    {
        q.push({bestr, bestc});
        int best = 0;
        while (!q.empty())
        {
            for (int j = 0; j < 4; j++)
            {
                nextr = q.front().first + dr[j];
                nextc = q.front().second + dc[j];
                if (nextr == n || nextr == -1 || nextc == n || nextc == -1)
                {
                    continue;
                }
                if (v[nextr][nextc] >= v[row][col])
                {
                    continue;
                }
                pushing(v, nextr, nextc, visit, q, i + 1, best, bestr, bestc);
            }
            q.pop();
        }
        row = bestr;
        col = bestc;
        if(best==0)
        {
            break;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &f);
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    int r, c;
    scanf("%d %d", &r, &c);
    r--;
    c--;
    vector<vector<int>> visit(n, vector<int>(n, 0));
    finding(r, c, v, visit);
    printf("%d %d", r + 1, c + 1);
    return 0;
}
