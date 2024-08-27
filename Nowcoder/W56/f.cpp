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
const int INF=1e9;
struct Hash{
    #define ll long long
    const int P1=233;
    const int mod1=1e9+7;
    const int P2=13331;
    const int mod2=1e9+9;
    string s;
    vector<ll>h1,h2,p1,p2;
    Hash(string t){
        s=' '+t;
        h1.resize(s.size());h2.resize(s.size());
        p1.resize(s.size());p2.resize(s.size());
        p1[0]=p2[0]=1;
        for(int i=1;i<s.size();i++){
            p1[i]=p1[i-1]*P1%mod1;
            p2[i]=p2[i-1]*P2%mod2;
            h1[i]=(h1[i-1]*P1+s[i])%mod1;
            h2[i]=(h2[i-1]*P2+s[i])%mod2;
        }
    }
    pair<ll,ll> get(int l,int r){//下标从1开始
        ll res1=((h1[r]-h1[l-1]*p1[r-l+1])%mod1+mod1)%mod1;
        ll res2=((h2[r]-h2[l-1]*p2[r-l+1])%mod2+mod2)%mod2;
        return make_pair(res1,res2);
    }
};
void solve(){
    int n;cin>>n;
    string a,b;cin>>a>>b;
    string t=a;reverse(all(t));
    Hash h1(a);Hash h2(b);Hash h3(t);

    vector<int>dp(n+2);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i-1]==b[i-1])cnt++;
        else{
            for(int j=i-1;j>=i-cnt;j--){
                dp[j]=i-j;
            }
            cnt=0;
        }
    }
    for(int j=n;j>=n+1-cnt;j--)dp[j]=n+1-j;
        // return;


    int ans3=0,ans4=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(h2.get(1,mid)==h3.get(n-i+1,n-i+mid)){
                l=mid;
            }else r=mid;
        }
        if(l>ans3){
            ans3=l;
            ans4=i;
        }
    }
    // cout<<ans3<<' '<<ans4<<endl;

    // afds

    // sdfa

    // fdsa

    int ans=0,ans2=1;
    for(int i=1;i<=n;i++){
        if(h3.get(n-i+1,n)==h2.get(1,i)){
            // int l=0,r=n-i+1;
            // while(l+1!=r){
            //     int mid=l+r>>1;
            //     if(h1.get(i+1,i+mid)==h2.get(i+1,i+mid)){
            //         l=mid;
            //     }else r=mid;
            // }
            if(dp[i+1]+i>ans){
                ans=dp[i+1]+i;
                ans2=i;
            }
        }
    }
    if(ans3>ans){
        ans=ans3;
        ans2=ans4;
    }
    cout<<ans<<' '<<ans2<<endl;
}
signed main(){
    // ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}