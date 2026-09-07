#include <iostream>
using namespace std;
#include <vector>
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
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += v[i][0];
        dp[i][0] = temp;
    }
    temp = dp[0][0];
    for (int i = 1; i < n; i++)
    {
        temp += v[0][i];
        dp[0][i] = temp;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + v[i][j];
        }
    }
    printf("%d", dp[n - 1][n - 1]);

    return 0;
}