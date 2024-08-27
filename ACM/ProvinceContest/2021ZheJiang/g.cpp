#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=500010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int root[N];
int siz[N];
int find(int x) {
    while (x != root[x]) {
        x = root[x] = root[root[x]];
    }
    return x;
}
int cnt;
bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return false;
    }
    siz[x] += siz[y];
    root[y] = x;
    return true;
}
int dir[6][2]={1,0,0,1,-1,1,-1,0,0,-1,1,-1};
void solve(){
    int q;cin>>q;int n=1;
    for(int i=1;i<=5e5;i++)root[i]=i,siz[i]=6;
    map<pair<int,int>,int>mp;
    while(q--){
        int op,a,b;cin>>op>>a>>b;
        int idx;
        if(!mp.count({a,b}))mp[{a,b}]=n++;
        idx=mp[{a,b}];
        if(op==1){
            cnt=0;
            // int flag=0;
            // cout<<a<<' '<<b<<endl;
            for(int i=0;i<6;i++){
                int tx=dir[i][0]+a,ty=dir[i][1]+b;
                // cout<<'.'<<tx<<' '<<ty<<endl;
                if(!mp.count({tx,ty})){continue;}
                int t=mp[{tx,ty}];
                cnt++;
                merge(idx,t);
                // if(find(idx)!=find(t)){
                    // flag=t;
                // }
            }
            // cout<<idx<<' '<<cnt<<endl;
            siz[find(idx)]-=cnt*2;
            // cout<<siz[find(idx)]<<endl;
            // cout<<siz[find(idx)]<<endl;
            // if(flag){
            //     merge(idx,flag);
            // }
            // cout<<siz[find(idx)]<<endl;
        }else{
            cout<<siz[find(idx)]<<endl;;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}