#include <iostream>
#include <cstdio>
using namespace std;
#include <vector>
int n, m;

void finding(vector<int> &v,int start)
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
    for (int i = start; i <= n; i++)
    {
        v.push_back(i);
        finding(v,i+1);
        v.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    vector<int> v;
    finding(v,1);
    return 0;
}
