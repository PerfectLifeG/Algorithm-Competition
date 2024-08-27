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
#define x first
#define y second
PII a[N];
int b[N];
void solve(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y;
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        cin>>b[i];
    }
    int l=0,r=q+1;
    while(l+1!=r){
        int mid=l+r>>1;
        int sum[N]={0};
        for(int i=1;i<=mid;i++){
            sum[b[i]]=1;
        }
        for(int i=1;i<=n;i++){
            sum[i]+=sum[i-1];
        }
        int f=0;
        for(int i=1;i<=m;i++){
            int t=sum[a[i].y]-sum[a[i].x-1];
            if(t>(a[i].y-a[i].x+1)/2){f=1;break;}
        }
        if(f)r=mid;
        else l=mid;
    }
    if(r==q+1)cout<<-1<<endl;
    else cout<<r<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T=1;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}