#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, m;

void pushing(queue<pair<int, int>> &q, vector<int> &dp, int cnt, int location)
{
    if (location < 0 || location > m)
    {
        return;
    }
    if (dp[location] <= cnt)
    {
        return;
    }
    q.push({location, cnt});
    dp[location] = cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    vector<int> dp(m + 1, m + 1);
    dp[0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        int location = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (location == m)
        {
            printf("%d", cnt);
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            int nl = location + v[i];
            int nc = cnt + 1;
            pushing(q, dp, nc, nl);
        }
    }
    printf("-1");
    return 0;
}