#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    for (int k = 0; k < t; k++)
    {
        int n;cin>>n;
        int a;cin>>a;int b;
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        int i = 0;
        for (; i < n-1; i++)
        {
            cin>>b;
        }
        if(b-a<=(i+2))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}