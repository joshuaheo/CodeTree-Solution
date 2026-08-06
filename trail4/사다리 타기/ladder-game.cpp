#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n, m,answer=0;

void result(vector<pair<int, int>> v, vector<int> &number, int col)
{
    if (col == 15)
    {
        return;
    }
    for (int i = 0; i < m; i++)
    {
        if (v[i].second == col)
        {
            swap(number[v[i].first], number[v[i].first + 1]);
        }
    }
    result(v, number, col + 1);
}
void find(vector<int> &number,int target)
{
    if(target == n)
    {
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(number[i]==target+1)
        {
            int temp=i;
            while((target+1)!=number[target])
            {
                swap(number[temp],number[temp-1]);
                answer++;
                temp--;
            }
        }
    }
    find(number,target+1);
}

int main()
{
    int a, b;
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> v(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        v[i] = {a - 1, b - 1};
    }
    vector<int> number(n);
    for (int i = 0; i < n; i++)
    {
        number[i] = i + 1;
    }
    result(v, number, 0);
    find(number,0);
    printf("%d",answer);
    return 0;
}