#include <iostream>
#include <vector>
using namespace std;

vector<int> answer; 
void select(int n,int k)
{
    if(n==0)
    {
        for(int i=0;i<answer.size();i++)
        {
            printf("%d ",answer[i]);
        }
        printf("\n");
        return;
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            answer.push_back(i);
            select(n-1,k);
            answer.pop_back();
        }
    }
}

int main() {
    // Please write your code here.
    int k,n;
    scanf("%d %d",&k,&n);
    select(n,k);
    return 0;
}