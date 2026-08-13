#include <iostream>
using namespace std;

int count=0;
void beauty(int n)
{
    if(n==0)
    {
        count++;
        return;
    }
    else if(n<0)
    {
        return;
    }
    for(int i=1;i<=4;i++)
    {
        beauty(n-i);
    }

}

int main() {
    // Please write your code here.
    int n;
    scanf("%d",&n);
    if(n>=1){
        beauty(n);
    }
    printf("%d",count);
    return 0;
}