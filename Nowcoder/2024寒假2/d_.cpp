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
const int N=5050;
const int mod=998244353;
const int INF=1e18;
int n,m,k;
void solve(){
    cin>>n>>m>>k;
    PII edge[m];
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        edge[i]={a,b};
    }
    int d[n+1]={};
    int book[n+1]={};
    for(int i=1;i<=n;i++)d[i]=1e18;
    d[k]=0;
    for(int p=0;p<n;p++){
        int mn=INF;int t=k;
        for(int i=1;i<=n;i++){//找最近的点
            if(book[i]==0&&d[i]<=mn){
                mn=d[i];
                t=i;
            }
        }
        // cout<<t<<endl;
        if(t==n)break;
        book[t]=1;
        // for(int j=1;j<=n;j++){//松弛出边
        //     if(book[j])continue;
        //     d[j]=min(d[j],d[t]+);
        // }
        for(int j=0;j<m;j++){//松弛出边
            if(book[(t+edge[j].x+n-1)%n+1])continue;
            d[(t+edge[j].x+n-1)%n+1]=min(d[(t+edge[j].x-1+n)%n+1],d[t]+edge[j].y);
            // cout<<t<<' '<<(t+edge[j].x+n-1)%n+1<<' '<<d[(t+edge[j].x+n-1)%n+1]<<endl;
        }
    }
    if(d[n]==1e18)cout<<-1<<endl;
    else cout<<d[n]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}