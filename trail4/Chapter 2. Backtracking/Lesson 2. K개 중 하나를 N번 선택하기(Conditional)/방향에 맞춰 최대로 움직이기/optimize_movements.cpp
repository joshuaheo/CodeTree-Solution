#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int n, answer = 0;

bool moving(int direction, int &row, int &col)
{
    int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    row = row + drow[direction];
    col = col + dcol[direction];
    if (row < 0 || row >= n || col < 0 || col >= n)
    {
        row -= drow[direction];
        col -= dcol[direction];
        return false;
    }
    return true;
}

void finding(vector<vector<int>> &v, vector<vector<int>> &d, vector<vector<int>> &memozi, int row, int col)
{
    if(memozi[row][col]!=-1)
    {
        return;
    }
    memozi[row][col]=0;
    bool flag = true;
    int brow = row, bcol = col;
    while (flag)
    {
        flag = moving(d[brow][bcol] - 1, row, col);
        if (flag == true)
        {
            if (v[row][col] > v[brow][bcol])
            {
                finding(v, d, memozi, row, col);
                memozi[brow][bcol]=max(memozi[brow][bcol],1+memozi[row][col]);
            }
        }
    }
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
    vector<vector<int>> memozi(n, vector<int>(n, -1));
    int r, c;
    scanf("%d %d", &r, &c);
    r = r - 1;
    c = c - 1;
    finding(v, d, memozi, r, c);
    printf("%d", memozi[r][c]);
    return 0;
}
