#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;int l;
    cin>>n>>l;
    int len=l;int cnt=26;
    for (int i = 0; i < n; i++)
    {
        int Y,G,R;
        string a,b;cin>>a>>b;
        for (int i = 0; i < l; i++)
        {
            if(b[i]=='G')
            {len--;G++;}
            if(b[i]=='R')
            {cnt--;R++;}
            if(b[i]=='Y')
            {cnt--;Y++;}
        }
        if(l-G==Y)len--;
        for (int i = 0; i < len; i++)
        {
            
        }
        
    }
    
    return 0;
}