#include <iostream>
using namespace std;
#include <vector>

int k, n;
void finding(vector<int> &v)
{
    if (v.size() == n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",v[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (v.size() <= 1 || ((v.back() != i) || (v[v.size() - 2] != i)))
        {
            v.push_back(i);
            finding(v);
            v.pop_back();
        }
    }
}

int main()
{
    scanf("%d %d", &k, &n);
    vector<int> v;
    finding(v);
    return 0;
}