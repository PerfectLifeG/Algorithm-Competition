#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n;
    cin>>n;
    int r=n*1.0/2.718;int flag=0;int m=0;
    for (int i = 1; i <= r; i++)
    {
        int b;cin>>b;
        if(b>m){m=b;
        flag=i;
        }
    }
    int q;int f=0;
    for (int i = r+1; i <= n; i++)
    {
        int b;cin>>b;
        if(b>m){
            q=i;
            f=1;
            break;
        }
    }
    
    return 0;
}