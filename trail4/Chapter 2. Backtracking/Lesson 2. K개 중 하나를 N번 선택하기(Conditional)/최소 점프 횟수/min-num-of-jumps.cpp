#include <iostream>
using namespace std;
#include <vector>
int n, answer = -1;
void finding(vector<pair<int, int>> &v, int location)
{
    if (location == 0)
    {
        answer = v[0].second;
        return;
    }
    for (int i = 1; i <= 4; i++)
    {
        if(location-i<0)
        {
            break;
        }
        if (v[location - i].first >= i)
        {
            if(v[location-i].second<=v[location].second+1)
            {
                continue;
            }
            v[location-i].second=v[location].second+1;
            finding(v,location-i);
        }
    }
}

int main()
{
    scanf("%d", &n);
    vector<pair<int, int>> v(n, {0, 11});
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i].first);
    }
    v[n-1].second=0;
    finding(v, n - 1);
    printf("%d", answer);
    return 0;
}
