#include <iostream>
using namespace std;
#include <vector>
int n;

void finding(vector<int> &v)
{
    int temp = v.size() - 2;
    bool flag = false;
    for (int i = 1; i <= v.size() / 2; i++)
    {
        for (int j = temp; j < temp+i; j++)
        {
            if (v[j] != v[i+j])
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            flag = false;
            temp -= 2;
        }
        else
        {
            v.back()=-1;
            return;
        }
    }
    if (v.size() == n)
    {
        return;
    }
    for (int i = 4; i <= 6; i++)
    {
        v.push_back(i);
        finding(v);
        if (v.size() == n && v.back()!=-1)
        {
            return;
        }
        v.pop_back();
    }
}

int main()
{
    scanf("%d", &n);
    vector<int> v;
    finding(v);
    for (int i = 0; i < v.size(); i++)
    {
        printf("%d", v[i]);
    }
    return 0;
}