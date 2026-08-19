#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
vector<pair<int, int>> position;
void result(int bomb, vector<vector<int>> v, int k)
{
    if (bomb == -1)
    {
        int temp = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (v[i][j] == 1)
                {
                    temp++;
                }
            }
        }
        if (temp > answer)
        {
            answer = temp;
        }
        return;
    }
    int x = position[bomb].first;
    int y = position[bomb].second;
    if (k == 0)
    {
        for (int j = x - 2; j <= x + 2; j++)
        {
            if (j >= 0 && j < v.size())
            {
                v[j][y] = 1;
            }
        }
        k++;
    }
    else if (k == 1)
    {
        for (int j = x - 1; j <= x + 1; j++)
        {
            if (j >= 0 && j < v.size())
            {
                v[j][y] = 1;
            }
        }
        for (int j = y - 1; j <= y + 1; j++)
        {
            if (j >= 0 && j < v.size())
            {
                v[x][j] = 1;
            }
        }
        k++;
    }
    else if (k == 2)
    {
        if ((x - 1) >= 0 && (y - 1) >= 0)
        {
            v[x - 1][y - 1] = 1;
        }
        if ((x - 1) >= 0 && (y + 1) < v.size())
        {
            v[x - 1][y + 1] = 1;
        }
        if ((x + 1) < v.size() && (y - 1) >= 0)
        {
            v[x + 1][y - 1] = 1;
        }
        if ((x + 1) < v.size() && (y + 1) < v.size())
        {
            v[x + 1][y + 1] = 1;
        }
        k = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        result(bomb - 1, v, i);
    }
}

int main()
{
    // Please write your code here.
    int n;
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 1)
            {
                position.push_back({i, j});
            }
        }
    }
    vector<vector<int>> k = v;
    int bomb = position.size();
    for (int i = 0; i < 3; i++)
    {
        result(bomb - 1, v, i);
    }
    printf("%d",answer);
    return 0;
}