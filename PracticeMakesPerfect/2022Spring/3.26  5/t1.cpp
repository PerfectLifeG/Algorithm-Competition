#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int book[100];
int main()
{
    int n, m;
    cin>>n>>m;
    m%=n;
    int pass=0;
    int step=0;
    for (int i = 0; i < n; i++)
    {
        while (step!=m)
        {
            pass++;
            if(pass>n)pass%=n;
            if(book[pass]==0)step++;
        }
        printf("%d ",pass);
        book[pass]=1;
        step=0;
        m++;
    }
    
    return 0;
}