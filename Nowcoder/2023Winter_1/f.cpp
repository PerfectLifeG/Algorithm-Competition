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
int root[N];
int siz[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra==rb)return;
    if(ra>rb)swap(ra,rb);
    siz[ra]+=siz[rb];
    root[rb]=root[ra];
}
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)root[i]=i,siz[i]=1;
    while(m--){
        int a,b;cin>>a>>b;
        merge(a,b);
    }
    // for(int i=1;i<=n;i++)cout<<i<<' '<<root[i]<<' '<<siz[i]<<endl;
    int r=-1;
    int flag=0;
    for(int i=1;i<=n;i++){
        int a;cin>>a;
        if(a&&r!=-1&&find(i)!=r){
            cout<<0<<endl;
            return;
        }
        if(a){r=find(i);flag++;}
    }
    if(flag==0){
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
            int t=find(i);
            if(r==-1||!mp.count(t)){
                mp[t]=1;
                ans+=siz[t]*(siz[t]-1);
                r=t;
            }
        }
        cout<<ans+n<<endl;
    }
    else cout<<siz[r]*(siz[r]-1)+siz[r]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}