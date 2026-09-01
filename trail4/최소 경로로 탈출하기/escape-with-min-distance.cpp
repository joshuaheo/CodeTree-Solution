#include <iostream>
using namespace std;
#include <vector>
#include <queue>
int n, m;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void pushing(queue<pair<int, int>> &q, vector<vector<int>> &visit, int row, int col)
{
    if (row == -1 || row == n || col == -1 || col == m)
    {
        return;
    }
    if (visit[row][col] == 1)
    {
        return;
    }
    q.push({row, col});
    visit[row][col] = 1;
}

int main()
{
    int count = 0;
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> visit(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &v[i][j]);
            if (v[i][j] == 0)
            {
                visit[i][j] = 1;
            }
        }
    }
    visit[0][0] = 1;
    queue<pair<int, int>> q;
    queue<pair<int, int>> f;
    bool flag = false;
    q.push({0, 0});
    while (!q.empty())
    {
        count++;
        f=q;
        while(!f.empty())
        {
            int drow,dcol;
            for(int i=0;i<4;i++)
            {
                drow=f.front().first+dr[i];
                dcol=f.front().second+dc[i];
                if(drow==n-1 && dcol== m-1)
                {
                    flag=true;
                    break;
                }
                pushing(q,visit,drow,dcol);
            }
            if(flag==true)
            {
                break;
            }
            f.pop();
            q.pop();
        }
        if(flag==true)
        {
            break;
        }
    }
    if(flag==false)
    {
        count=-1;
    }
    printf("%d",count);
    return 0;
}