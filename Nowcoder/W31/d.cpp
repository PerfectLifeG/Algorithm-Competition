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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int node[N];
int nx[N];
int pre[N];
unordered_map<int,int>pos;
void solve(){
    int n;cin>>n;
    int h=0;
    nx[h]=-1;
    pre[h]=0;
    pos[0]=0;
    int idx=1;
    while(n--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;
                node[idx]=x;
                pos[x]=idx;

                pre[idx]=pos[y];
                nx[idx]=nx[pos[y]];
                pre[nx[idx]]=idx;
                nx[pos[y]]=idx;

                idx++;
        }else{
            int x;cin>>x;
            if(pos.count(x)){
                nx[pre[pos[x]]]=nx[pos[x]];
                pre[nx[pos[x]]]=pre[pos[x]];
                pos.erase(x);
            }
        }
    }
    int t=0;
    vector<int>ans;
    while(nx[t]!=-1){
        ans.push_back(node[nx[t]]);
        t=nx[t];
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}