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
int main()
{
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        int x,y;
        cin>>x>>y;
        if(x%y!=0){cout<<-1<<endl;continue;}
        int cnt=0;
        for (int n = 1; n <= x/y*2+1; n++)
        {
            for (int m = 1; m <= n; m++)
            {
                if(1.0*(n+1)/2-1.0*m/n==1.0*x/y)
                    cnt^=n+m;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}