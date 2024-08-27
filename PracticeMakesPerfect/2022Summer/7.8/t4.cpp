#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s=0;
    int a,b;cin>>a>>b;
    if(a>b)b=1;
    else a=1;
    s+=abs(b-a);
    a=b;
    for (int i = 0; i < n-2; i++)
    {
        cin>>b;
        if(a!=1)b=1;
        s+=abs(b-a);
        a=b;
    }
    cout<<s;
    return 0;
}