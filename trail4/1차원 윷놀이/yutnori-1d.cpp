#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n, m, k, answer = 0;

void finding(vector<int> &moving, vector<int> &player, int index, int counting, int selection)
{
    if (answer == k)
    {
        return;
    }
    if (index == n)
    {
        answer = max(counting, answer);
        return;
    }
    if (selection != -1)
    {
        if ((player[selection] + moving[index]) >= m)
        {
            counting++;
            player[selection] = m;
            if (counting == k)
            {
                answer = k;
                return;
            }
        }
        else
        {
            player[selection] += moving[index];
        }
    }
    int temp;
    for (int i = 0; i < k; i++)
    {
        if (player[i] < m)
        {
            temp=player[i];
            finding(moving, player, index + 1, counting, i);
            player[i]=temp;
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    vector<int> player(k, 1);
    vector<int> moving;
    int temp;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        moving.push_back(temp);
    }
    finding(moving, player, -1,0, -1);
    printf("%d", answer);
    return 0;
}