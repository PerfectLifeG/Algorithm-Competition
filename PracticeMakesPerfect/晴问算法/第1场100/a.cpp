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
    int n,k;cin>>n>>k;
    vector<PII>v;
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v),[&](PII a,PII b){
        if(a.x!=b.x)return a.x<b.x;
        return a.y>b.y;
    });
    int lst=0;
    for(int i=0;i<k;i++){
        if(v[i].x<=lst+1){
            lst=max(lst,v[i].y);
        }else {no;return;}
    }
    if(lst>=n-1)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}