#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n;
int main()
{
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = v[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = min(dp[0][i - 1], v[0][i]);
        dp[i][0] = min(dp[i - 1][0], v[i][0]);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(max(dp[i - 1][j], dp[i][j - 1]), v[i][j]);
        }
    }
    printf("%d", dp[n - 1][n - 1]);
    return 0;
}