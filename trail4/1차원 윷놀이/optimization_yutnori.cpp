#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n, m, k, answer = 0;

void finding(vector<int> &moving, vector<int> &player, int index, int counting)
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
    int temp, temp2;
    bool arrival=0;
    for (int i = 0; i < k; i++)
    {
        if (player[i] < m)
        {
            temp = player[i];
            if ((player[i] + moving[index]) >= m)
            {
                arrival=1;
                player[i] = m;
                if (counting == k+arrival)
                {
                    answer = k;
                    return;
                }
            }
            else
            {
                player[i] += moving[index];
            }

            finding(moving, player, index + 1, counting+arrival);
            player[i] = temp;
            arrival=0;
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
    finding(moving, player, 0, 0);
    printf("%d", answer);
    return 0;
}
