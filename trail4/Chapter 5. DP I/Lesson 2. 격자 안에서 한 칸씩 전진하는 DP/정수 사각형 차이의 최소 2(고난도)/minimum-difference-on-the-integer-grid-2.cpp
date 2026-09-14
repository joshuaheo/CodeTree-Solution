#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main()
{
    int n;
    int result = 100;
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    vector<vector<int>> dp;
    int temp = min(v[0][0], v[n - 1][n - 1]);
    for (int i = 1; i <= temp; i++)
    {
        dp.assign(n, vector<int>(n, -1));
        dp[0][0] = v[0][0];
        for (int j = 1; j < n; j++)
        {
            if (dp[0][j - 1] != -1 && v[0][j] >= i)
            {
                dp[0][j] = max(v[0][j], dp[0][j - 1]);
            }
            if (dp[j - 1][0] != -1 && v[j][0] >= i)
            {

                dp[j][0] = max(v[j][0], dp[j - 1][0]);
            }
        }
        for (int k = 1; k < n; k++)
        {
            for (int t = 1; t < n; t++)
            {
                if (v[k][t] < i)
                {
                    continue;
                }
                if (dp[k - 1][t] == -1 && dp[k][t - 1] == -1)
                {
                    continue;
                }
                else if (dp[k - 1][t] == -1 || dp[k][t - 1] == -1)
                {
                    if (dp[k - 1][t] == -1)
                    {
                        dp[k][t] = max(dp[k][t - 1],v[k][t]);
                    }
                    else
                    {
                        dp[k][t] = max(dp[k - 1][t],v[k][t]);
                    }
                    continue;
                }
                dp[k][t] = max(min(dp[k - 1][t], dp[k][t - 1]),v[k][t]);
            }
        }
        if (dp[n - 1][n - 1] != -1)
        {
            result = min(dp[n - 1][n - 1] - i, result);
        }
    }
    printf("%d", result);
    return 0;
}