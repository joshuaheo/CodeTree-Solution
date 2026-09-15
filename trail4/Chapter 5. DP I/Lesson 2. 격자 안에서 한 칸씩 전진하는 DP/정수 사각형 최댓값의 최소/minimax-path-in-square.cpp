#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d",&n);
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,-1));
    dp[0][0]=v[0][0];
    for(int i=1;i<n;i++)
    {
        dp[i][0]=max(v[i][0],dp[i-1][0]);
        dp[0][i]=max(v[0][i],dp[0][i-1]);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=max(min(dp[i-1][j],dp[i][j-1]),v[i][j]);
        }
    }
    printf("%d",dp[n-1][n-1]);
    return 0;
}