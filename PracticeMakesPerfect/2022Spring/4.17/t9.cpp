#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>n>>m;
    map<int,int>mp;
    int s[n];
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 0; i < n/m; i++)
    {
        int a[m];
        for (int j = 0; j < m; j++)
        {
            cin>>a[j];
        }
        for (int j = m-1; j >=0 ; j--)
        {
            mp[s[m-1-j+i*m]]=a[j];
        }
    }
    int k;cin>>k;
    for (int i = 0; i < k; i++)
    {
        int p;cin>>p;
        if(mp.count(p)==1)
        cout<<mp[p]<<endl;
        else cout<<"Wrong Number"<<endl;
    }
    
    return 0;
}