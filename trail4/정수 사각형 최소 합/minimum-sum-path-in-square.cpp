#include <iostream>
using namespace std;
#include <vector>
int n;

int main()
{
    scanf("%d",&n);
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
    vector<vector<int>> dp(n,vector<int>(n));
    dp[0][n-1]=v[0][n-1];
    for(int i=n-2;i>=0;i--)
    {
        dp[0][i]=dp[0][i+1]+v[0][i];
    }
    for(int i=1;i<n;i++)
    {
        dp[i][n-1]=dp[i-1][n-1]+v[i][n-1];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=n-2;j>=0;j--)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j+1])+v[i][j];
        }
    }
    printf("%d",dp[n-1][0]);
    return 0;
}