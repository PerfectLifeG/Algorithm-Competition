#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=500010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int a[N];
int b[N];
int book[N];
int ini[N];
int p[N];
int n;
int check(int x){
    int t=0;
    for(int i=1;i<=n;i++){
        a[i]=ini[i];
    }
    while(x--){
        for(int i=1;i<=n;i++){
            b[p[i]]=a[i];
            // cout<<b[p[i]]<<' '<<ini[p[i]]<<endl;
            if(b[p[i]]==ini[p[i]]&&!book[p[i]]){book[p[i]]=1;t++;}
        }
        for(int i=1;i<=n;i++){
            a[i]=b[i];
        }
        if(t==n){
            return 1;
        }
    }
    return 0;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ini[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }

    // int t=0;
    // int u=5;
    // int ans=1;
    // while(u--){
        // for(int i=1;i<=n;i++){
        //     b[p[i]]=a[i];
        //     // cout<<b[p[i]]<<' '<<ini[p[i]]<<endl;
        //     if(b[p[i]]==ini[p[i]]&&!book[p[i]]){book[p[i]]=1;t++;}
        // }
        // for(int i=1;i<=n;i++){
        //     a[i]=b[i];
        // }
        // if(t==n){
        //     cout<<ans<<endl;
        //     return;
        // }
        // ans++;
    // }


    int l=0,r=n+1;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}