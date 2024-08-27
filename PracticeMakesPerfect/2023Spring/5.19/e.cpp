#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int root[N];
int find(int a){
    if(root[a]==a)return a;
    return root[a]=find(root[a]);
}
void merge(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra>rb)swap(ra,rb);
    root[ra]=rb;
}
void solve(){
    int n;cin>>n;
    int cnt2=0;
    for(int i=1;i<=n;i++)root[i]=i;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // cout<<a[i]<<'-'<<i<<' ';
        merge(a[i],i);
    }
    // cout<<endl;
    // int vis[N]={0};
    // for(int i=1;i<=n;i++){
    //     if(vis[i]==0&&vis[a[i]]==0&&a[a[i]]==i)cnt2++;
    //     vis[i]=1;
    //     vis[a[i]]=1;
    // }
    // for(int i=1;i<=n;i++){
    //     cout<<root[i]<<' ';
    // }
    // cout<<endl;
    int cnt=0;
    int book[N]={0};
    int vis[N];
    memset(vis,1,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(vis[find(a[i])]){
            if(a[a[i]]==i){cnt2++;vis[find(a[i])]=0;}
            
        }
        if(book[find(a[i])]==0){
            cnt++;
            book[find(a[i])]=1;
        }
    }
    // cout<<cnt2<<endl;
    if(cnt2==0)cout<<cnt<<' '<<cnt<<endl;
    else cout<<cnt-cnt2+1<<' '<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}