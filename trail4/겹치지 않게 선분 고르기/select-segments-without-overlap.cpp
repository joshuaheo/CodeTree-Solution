#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int answer = 0;

void select(vector<pair<int, int>> check, vector<pair<int, int>> v, int p)
{
    if (p == n)
    {
        int temp = check.size();
        answer = max(answer, temp);
        return;
    }
    select(check, v, p + 1);
    for (int i = 0; i < check.size(); i++)
    {
        if (!((check[i].first > v[p].second || check[i].second < v[p].first)))
        {
            return;
        }
    }
    check.push_back(v[p]);
    select(check, v, p + 1);
}

int main()
{
    scanf("%d", &n);
    vector<pair<int, int>> v;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }
    vector<pair<int, int>> check;
    select(check, v, 0);
    printf("%d", answer);
    return 0;
}