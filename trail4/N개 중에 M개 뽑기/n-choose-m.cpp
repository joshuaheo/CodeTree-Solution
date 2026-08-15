#include <iostream>
using namespace std;
#include <vector>
int n, m;

void finding(vector<int> &v)
{
    if (v.size() == m)
    {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    if (v.size() == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
            finding(v);
            v.pop_back();
        }
        return;
    }
    for (int i = v.back()+1; i <= n; i++)
    {
        v.push_back(i);
        finding(v);
        v.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    vector<int> v;
    finding(v);
    return 0;
}