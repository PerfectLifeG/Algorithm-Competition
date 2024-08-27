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
int n,m;
int v[N];
vector<PII>p;
int ans;
int cmp(int a,int b){
    if(v[a]==v[b])return a<b;
    return v[a]>v[b];
}
vector<int>temp;
void dfs(int cnt){
    if(cnt==p.size()){
        sort(all(temp),cmp);
        int rank=1;
        if(temp[0]!=1){
            for(int i=1;i<temp.size();i++){
                if(v[temp[i]]!=v[temp[i-1]])rank=i+1;
                if(temp[i]==1)break;
            }
        }
        ans=min(ans,rank);
        // if(ans==4){for(auto i:temp)cout<<i<<' ';cout<<endl;for(auto i:temp)cout<<v[i]<<' ';cout<<endl;}
        return;
    }
    v[p[cnt].x]+=3;
    dfs(cnt+1);
    v[p[cnt].x]-=3;

    v[p[cnt].y]+=3;
    dfs(cnt+1);
    v[p[cnt].y]-=3;

    v[p[cnt].y]+=1;
    v[p[cnt].x]+=1;
    dfs(cnt+1);
    v[p[cnt].y]-=1;
    v[p[cnt].x]-=1;

}
void solve(){
    cin>>n>>m;
    ans=n;
    temp.clear();p.clear();
    for(int i=1;i<=n;i++){temp.push_back(i);cin>>v[i];}
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        if(a==1)v[a]+=3;
        else{
            p.push_back({a,b});
        }
    }
    // for(auto i:p)cout<<i.x<<' '<<i.y<<endl;
    dfs(0);
    // if(!p.size()){
    //     sort(all(temp),cmp);
    //     int rank=1;
    //     for(int i=1;i<temp.size();i++){
    //         if(v[temp[i]]!=v[temp[i-1]])rank++;
    //         if(temp[i]==1)break;
    //     }
    //     ans=min(ans,rank);
    // }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}