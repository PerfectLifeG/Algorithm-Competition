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
    int t=n/2;
    int m=n%2;
    if(n==1){
        cout<<0<<endl;
        return;
    }
    vector<Node>v;
    for(int i=1;i<=n;i+=2){
        for(int j=1;j<=n;j+=2){
            if(i+1<=n&&j+1<=n){
                v.push_back({i,j,2});
            }
        }
    }
    if(m==0){
        int x=6*(t-1)+1;
        while(x>=1){
            if(n-x+1!=6)
            v.push_back({x,x,n-x+1});
            x-=6;
        }
    }
    else if(m==1){
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