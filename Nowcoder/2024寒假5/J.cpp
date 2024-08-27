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
    int n;cin>>n;
    vector<PII>v(n);
    int ans=0;
    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r;
        v[i]={l,r};
    }
    int x=v[0].x,y=v[0].y;
    for(int i=1;i<n;i++){
        if(v[i].y<=y&&v[i].y>=x&&v[i].x<x){
            y=v[i].y;
        }else if(v[i].x>=x&&v[i].y>y&&v[i].x<=y){
            x=v[i].x;
        }else if(v[i].x>=x&&v[i].y<=y){
            x=v[i].x;
            y=v[i].y;
        }else if(v[i].x>y){
            ans+=v[i].x-y;
            x=v[i].x;
            y=v[i].x;
        }else if(v[i].y<x){
            ans+=x-v[i].y;
            x=v[i].y;
            y=v[i].y;
        }
    }
    cout<<ans<<endl;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}