#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, f;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
bool arrive;

void pushing(vector<vector<int>> &v, int tempr, int tempc, vector<vector<int>> &visit, queue<pair<int, int>> &q, vector<vector<int>> &s)
{
    if (tempr == n || tempr == -1 || tempc == n || tempc == -1)
    {
        return;
    }
    if (visit[tempr][tempc] == 1)
    {
        return;
    }
    if (s[tempr][tempc] == 1)
    {
        return;
    }
    q.push({tempr, tempc});
    s[tempr][tempc] = 1;
}

bool checking(vector<vector<int>> &v, int row, int col, int drow, int dcol, vector<vector<int>> &visit)
{
    arrive = false;
    vector<vector<int>> s(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({row, col});
    s[row][col] = 1;

    while (!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();
        if (row == drow && col == dcol)
        {
            arrive = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int tempr = row + dr[i];
            int tempc = col + dc[i];
            pushing(v, tempr, tempc, visit, q, s);
        }
    }
    return arrive;
}
void masking(vector<vector<int>> &v, vector<vector<int>> &visit, int r, int c)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visit[i][j] == 1)
            {
                continue;
            }
            if (v[i][j] >= v[r][c])
            {
                visit[i][j] = 1;
            }
        }
    }
}

void finding(int &row, int &col, vector<vector<int>> &v, vector<vector<int>> &visit)
{
    if (f == 0)
    {
        return;
    }
    masking(v, visit, row, col);
    bool flag = false;
    for (int i = v[row][col] - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (visit[j][k] == 1)
                {
                    continue;
                }
                if (v[j][k] == i)
                {
                    for (int t = 0; t < 4; t++)
                    {
                        if (dr[t] + j != n && dr[t] + j != -1 && dc[t] + k != -1 && dc[t] + k != n)
                        {
                            if (v[dr[t] + j][dc[t] + k] < v[row][col] || (dr[t] + j == row && dc[t] + k == col))
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if (flag == true)
                    {
                        flag = checking(v, row, col, j, k, visit);
                    }
                    if (flag == true)
                    {
                        row = j;
                        col = k;
                        f--;
                        finding(row, col, v, visit);
                        return;
                    }
                }
            }
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