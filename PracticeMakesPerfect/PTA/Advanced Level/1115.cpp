#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int mx;
int dep[N];
int tree[N];
unordered_map<int,int>mp;
int idx;
void build(int t,int val,int depth){
    mx=max(mx,depth);
    // cout<<depth<<' '<<val<<' '<<t<<endl;
    if(!mp.count(t)){
        tree[idx]=val;
        dep[depth]++;
        mp[t]=idx++;
    }else{
        if(tree[mp[t]]>=val) build(2*t+1,val,depth+1);
        else build(2*t+2,val,depth+1);
    }
}
void solve(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        build(0,a,1);
    }
    cout<<dep[mx]<<" + "<<dep[mx-1]<<" = "<<dep[mx]+dep[mx-1]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}