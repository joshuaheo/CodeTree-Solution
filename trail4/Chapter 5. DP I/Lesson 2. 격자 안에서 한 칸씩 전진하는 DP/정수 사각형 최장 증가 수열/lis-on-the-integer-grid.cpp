#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int n;
int result = 0;
void finding(vector<vector<int>> &v, vector<vector<int>> &dp, int row, int col)
{
    int nr, nc;
    bool flag = false;
    for (int i = 0; i < 4; i++)
    {
        nr = row + dr[i];
        nc = col + dc[i];
        if (nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1)
        {
            continue;
        }
        if (v[nr][nc] > v[row][col])
        {
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        dp[row][col] = 1;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        nr = row + dr[i];
        nc = col + dc[i];
        if (nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1)
        {
            continue;
        }
        if (v[nr][nc] > v[row][col] && dp[nr][nc] == -1)
        {
            finding(v, dp, nr, nc);
        }
    }
    for (int i = 0; i < 4; i++)
    {
        nr = row + dr[i];
        nc = col + dc[i];
        if (nr < 0 || nr > n - 1 || nc < 0 || nc > n - 1)
        {
            continue;
        }
        if (v[nr][nc] > v[row][col])
        {
            dp[row][col] = max(dp[nr][nc], dp[row][col]);
        }
    }
    dp[row][col]++;
    result = max(dp[row][col], result);
}
int main()
{
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == -1)
            {
                finding(v, dp, i, j);
            }
        }
    }
    printf("%d", result);
    return 0;
}