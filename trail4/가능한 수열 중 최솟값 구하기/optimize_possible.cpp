#include <iostream>
using namespace std;
#include <vector>
int n;

bool finding(vector<int> &v)
{
    for (int i = 1; i <= v.size() / 2; i++)
    {
        int temp=v.size()-i*2;
        bool flag =false;
        for (int j = temp; j < temp+i; j++)
        {
            if (v[j] != v[i+j])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            return false;
        }
        
    }
    if (v.size() == n)
    {
        return true;
    }
    for (int i = 4; i <= 6; i++)
    {
        v.push_back(i);
        bool check=finding(v);
        if (check)
        {
            return true;
        }
        v.pop_back();
    }
    return false;
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
