#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for (int  i = 0; i < n; i++)
    {
        int m;cin>>m;
        unordered_map<int,int>mp;
        int flag=1;
        for (int i = 0; i < m; i++)
        {
            int a;cin>>a;
            if(flag==0)continue;
            if(mp.count(a)!=0)flag=0;
            else mp[a]++;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}