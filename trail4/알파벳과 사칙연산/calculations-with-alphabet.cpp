#include <iostream>
using namespace std;
#include <vector>
int calc2(char s, int a, int b)
{
    switch (s)
    {
    case '*':
        return a * b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
}
int calc(char s, vector<int> &v)
{
    switch (s)
    {
    case 'a':
        return v[0];
    case 'b':
        return v[1];
    case 'c':
        return v[2];
    case 'd':
        return v[3];
    case 'e':
        return v[4];
    case 'f':
        return v[5];
    }
}

void finding(string str, int index, int &result, vector<int> &v,bool &flag)
{
    if (index != 6)
    {
        for (int i = 1; i < 5; i++)
        {
            v.push_back(i);
            finding(str, index + 1, result, v,flag);
            v.pop_back();
        }
        return;
    }
    int current = calc(str[0], v);
    for (int i = 1; i < str.size(); i += 2)
    {
        current = calc2(str[i], current, calc(str[i + 1], v));
    }
    if(flag==false)
    {
        result=current;
        flag=true;
    }
    result = max(result, current);
}

int main()
{
    int result;
    bool flag=false;
    char str[200];
    vector<int> v;
    scanf("%s", str);
    finding(str, 0, result, v,flag);
    printf("%d", result);
    return 0;
}