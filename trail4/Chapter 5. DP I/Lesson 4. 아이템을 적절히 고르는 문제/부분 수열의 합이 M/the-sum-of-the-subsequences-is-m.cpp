#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    vector<int> dp(m + 1, n + 1);

    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            if (dp[j - a[i]] != n + 1)
            {
                dp[j] = min(dp[j], dp[j - a[i]] + 1);
            }
        }
    }

    if (dp[m] == n + 1)
    {
        printf("-1");
    }
    else
    {
        printf("%d", dp[m]);
    }

    return 0;
}