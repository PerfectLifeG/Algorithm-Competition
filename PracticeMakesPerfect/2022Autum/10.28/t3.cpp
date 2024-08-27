#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    for (int i = 0; i < t; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        int n=0;
        if(k==0){
            if(l==0&&r==0)cout<<"0"<<endl;
            else if(l==0&&r!=0)cout<<"0 1"<<endl;
            else if(l==1)cout<<"1"<<endl;
            else cout<<"None."<<endl;
            continue;
        }
        if(k==1){
            if(l==1)cout<<"1"<<endl;
            else if(l==0&&r>=1)cout<<"1"<<endl;
            else cout<<"None."<<endl;
            continue;
        }
        int flag=0;int t=k;
        if(l==1){cout<<1<<' ';flag=1;}
        while(k<=r)
        {
            if(k>=l){cout<<k<<' ';flag=1;}
            if(k*t/t!=k)break;
            if(k*t%t!=0)break;
            if(k*t<k)break;
            k*=t;
        }
        if(flag)cout<<endl;
        else cout<<"None."<<endl;
    }
    return 0;
}