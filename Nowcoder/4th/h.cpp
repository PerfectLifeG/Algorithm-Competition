#include<bits/stdc++.h>
using namespace std;
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int mod=998244353;
const int INF=0x3f3f3f3f;
struct Node{
    int a,b,c;
};
void solve()
{
    int n;cin>>n;
    int t=n/6;
    int m=n%6;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    vector<Node>v;
    for(int i=1;i<=n;i+=6){
        for(int j=1;j<=n;j+=6){
            if(i+5<=n&&j+5<=n){
                v.push_back({i,j,6});
            }
        }
    }
    // return;
    if(m==0||m==1){
        int x=6*(t-1)+1;
        while(x>=1){
            if(n-x+1!=6)
            v.push_back({x,x,n-x+1});
            x-=6;
        }
    }
    else if(m==2){
        int a=6*t+1;
        for(int i=1;i<n-2;i+=2){
            v.push_back({a,i,2});
        }
        for(int i=1;i<n-2;i+=2){
            v.push_back({i,a,2});
        }
        v.push_back({n-1,n-1,2});
        int x=6*(t-1)+1;
        while(x>=1){
            if(n-x+1!=6)
            v.push_back({x,x,n-x+1});
            x-=6;
        }
    }else if(m==3){
        int a=6*t+1;
        for(int i=1;i<n-3;i+=3){
            v.push_back({a,i,3});
        }
        for(int i=1;i<n-3;i+=3){
            v.push_back({i,a,3});
        }
        v.push_back({n-2,n-2,3});
        int x=6*(t-1)+1;
        while(x>=1){
            if(n-x+1!=6)
            v.push_back({x,x,n-x+1});
            x-=6;
        }
    }else if(m==4){
        int a=6*t+1;
        for(int i=1;i<n-4;i+=4){
            v.push_back({a,i,4});
        }
        for(int i=1;i<n-4;i+=4){
            v.push_back({i,a,4});
        }
        v.push_back({n-3,n-3,4});
        int x=n-15;
        while(x>=1){
            if(n-x+1!=6)
            v.push_back({x,x,n-x+1});
            x-=12;
        }
        if(x+12!=1){
            v.push_back({1,1,n});
        }
    }else if(m==5){
        int a=6*t+1;
        for(int i=1;i<n-5;i+=5){
            v.push_back({a,i,5});
        }
        for(int i=1;i<n-5;i+=5){
            v.push_back({i,a,5});
        }
        v.push_back({n-4,n-4,5});
        int x=n-34;
        while(x>=1){
            if(n-x+1!=6)
            v.push_back({x,x,n-x+1});
            x-=30;
        }
        if(x+30!=1){
            v.push_back({1,1,n});
        }
    }
    cout<<v.size()<<endl;
    for(auto i:v){
        cout<<i.a<<' '<<i.b<<' '<<i.c<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    // cin>>_;
    while(_--)solve();
    return 0;
}