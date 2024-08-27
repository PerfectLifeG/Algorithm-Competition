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
int ans;
int s[4];
void dfs(int t,int now){
    cout<<t<<' '<<now<<' ';for(int i=0;i<4;i++)cout<<s[i]<<' ';cout<<endl;
    // cout<<t<<' '<<s[t]<<' '<<now<<endl;
    // for(int i=0;i<4;i++)cout<<s[i]<<' ';cout<<endl;
    // if(now>=ans)return;
    if(t==4){
        // for(int i=0;i<4;i++){
        //     // cout<<s[i]<<'.';
        //     if(s[i])return;
        // }
        // cout<<endl;
        ans=min(ans,now);
        // cout<<ans<<endl;
        return;
    }
    if(s[t]==0){
        dfs(t+1,now);
        return;
    }
    int cnt=0;
    vector<int>ss(4);
    for(int i=0;i<4;i++)ss[i]=s[i];
    int p=s[t];
    for(int i=t;i<4;i++){
        if(s[i]-p<=0)s[i]=0,cnt++;
        else s[i]=(s[i]-p+10)%10;
    }
    for(int i=3;i>=t;i--){
        dfs(t+1,now+abs(p+cnt));
        s[i]=ss[i];
    }
    p=10-s[t];
    for(int i=t;i<4;i++){
        if(s[i]+p>=10)s[i]=0;
        else s[i]=(s[i]+p)%10;
    }
    for(int i=3;i>=t;i--){
        dfs(t+1,now+abs(p));
        s[i]=ss[i];
    }
}
void solve(){
    ans=1e18;
    int t=0;
    int a,b;cin>>a>>b;
    for(int i=0;i<4;i++){
        s[3-i]=(a%10-b%10+10)%10;
        a/=10;
        b/=10;
    }
    // for(int i=0;i<4;i++)cout<<s[i]<<' ';cout<<endl;
    dfs(0,0);
    // for(int i=0;i<4;i++)cout<<s[i]<<' ';cout<<endl;
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}