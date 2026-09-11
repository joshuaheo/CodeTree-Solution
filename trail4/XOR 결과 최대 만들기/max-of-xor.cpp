#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n, m;
int result = 0;

void finding(vector<int> &v, vector<int> &df, int start)
{

    if (df.size() == m)
    {
        int temp = df[0];
        for (int i = 1; i < m; i++)
        {
            temp = (temp ^ df[i]);
        }
        result = max(result, temp);
        return;
    }
    if (start == n)
    {
        return;
    }

    for (int i = start; i < n; i++)
    {
        df.push_back(v[i]);
        finding(v, df, i + 1);
        df.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    vector<int> df;
    finding(v,df,0);
    printf("%d", result);
    return 0;
}