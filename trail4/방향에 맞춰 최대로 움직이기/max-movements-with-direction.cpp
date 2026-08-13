#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n, answer = 0;

bool moving(int direction, int &x, int &y)
{
    switch (direction)
    {
    case 1:
        if (y != 0)
        {
            y--;
            return true;
        }
        else
        {
            return false;
        }
    case 2:
        if (y != 0 && x != n - 1)
        {
            y--;
            x++;
            return true;
        }
        else
        {
            return false;
        }
    case 3:
        if (x != n - 1)
        {
            x++;
            return true;
        }
        else
        {
            return false;
        }
    case 4:
        if (y != n - 1 && x != n - 1)
        {
            x++;
            y++;
            return true;
        }
        else
        {
            return false;
        }
    case 5:
        if (y != n - 1)
        {
            y++;
            return true;
        }
        else
        {
            return false;
        }
    case 6:
        if (x != 0 && y != n - 1)
        {
            x--;
            y++;
            return true;
        }
        else
        {
            return false;
        }
    case 7:
        if (x != 0)
        {
            x--;
            return true;
        }
        else
        {
            return false;
        }
    case 8:
        if (x != 0 && y != 0)
        {
            x--;
            y--;
            return true;
        }
        else
        {
            return false;
        }
    }
}

void finding(vector<vector<int>> &v, vector<vector<int>> &d, int x, int y, int count)
{
    if (v[y][x] == n * n)
    {
        answer = max(answer, count);

        return;
    }
    bool flag = true;
    int bx = x, by = y;
    while (flag)
    {
        flag = moving(d[by][bx], x, y);
        if (flag == true)
        {
            if (v[y][x] > v[by][bx])
            {
                finding(v, d, x, y, count + 1);
            }
        }
    }
    answer = max(answer, count);
}

int main()
{
    scanf("%d", &n);
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &d[i][j]);
        }
    }
    int r, c;
    scanf("%d %d", &r, &c);
    r = r - 1;
    c = c - 1;
    finding(v, d, c, r, 0);
    printf("%d", answer);
    return 0;
}