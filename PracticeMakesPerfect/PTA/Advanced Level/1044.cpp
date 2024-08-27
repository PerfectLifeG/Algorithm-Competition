#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,w;cin>>n>>w;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>s(n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int l=1,r=1;
    vector<PII>ans;
    int mx=1e9;
    while(r<=n){
        if(s[r]-s[l-1]==w){
            ans.push_back({l,r});
            if(r<=n)l++,r++;
        }else{
            while(l<=r&&s[r]-s[l-1]>w){mx=min(mx,s[r]-s[l-1]);l++;}
            if(s[r]-s[l-1]==w)ans.push_back({l,r});
            r++;
        }
    }
    if(ans.size())
        for(auto i:ans){cout<<i.x<<'-'<<i.y<<endl;}
    else{
        w=mx;
        l=1,r=1;
        while(r<=n){
        if(s[r]-s[l-1]==w){
            ans.push_back({l,r});
            if(r<=n)l++,r++;
        }else{
            while(l<=r&&s[r]-s[l-1]>w)l++;
                if(s[r]-s[l-1]==w)ans.push_back({l,r});
                r++;
            }
        }
        for(auto i:ans){cout<<i.x<<'-'<<i.y<<endl;}
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}