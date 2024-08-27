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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m,x,y;cin>>n>>m>>x>>y;
    x--,y--;
    string g[n];
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int q,p;cin>>p>>q;
    vector<PII>v;
    for(int i=0;i<q;i++){
        int a,b;cin>>a>>b;
        a,b--;
        v.push_back({a,b});
    }
    reverse(all(v));
    for(int k=0;k<p;k++){
        for(int i=0;i<v.size();i++){
            // cout<<v[i].x<<' '<<v[i].y<<endl;
            if(v[i].x==1&&v[i].y==x){
                y=((y-1)%m+m)%m;
            }else if(v[i].x==2&&v[i].y==y){
                x=((x-1)%n+n)%n;
            }
        }
    }
    cout<<g[x][y]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}