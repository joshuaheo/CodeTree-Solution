#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, k;
void pushing(queue<pair<int, int>>& q,vector<vector<int>> &visit,vector<vector<int>> &v,int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=n)
    {
        return;
    }
    if(v[y][x]==1)
    {
        return;
    }
    if(visit[y][x]==1)
    {
        return;
    }
    q.push({y,x});
    visit[y][x]=1;
}
int main()
{
    scanf("%d %d", &n, &k);
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    vector<pair<int, int>> start_point(k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d", &start_point[i].first, &start_point[i].second);
        start_point[i].first--;
        start_point[i].second--;
    }
    queue<pair<int, int>> q;
    vector<vector<int>> visit(n, vector<int>(n, 0));
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    int x,y;
    for (int i = 0; i < k; i++)
    {
        q.push(start_point[i]);
        visit[start_point[i].first][start_point[i].second]=1;
        while (!q.empty())
        {
            x=q.front().second;
            y=q.front().first;
            for(int j=0;j<4;j++)
            {
                pushing(q,visit,v,x+dx[j],y+dy[j]);
            }
            q.pop();
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]==1)
            {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}