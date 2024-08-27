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
void solve(){
    int n;cin>>n;
    vector<int>v(n+2);
    int sum=0;
    for(int i=1;i<=n;i++){cin>>v[i];sum+=v[i];}
    vector<int>s(n+2);
    for(int i=1;i<=n+1;i++)s[i]=s[i-1]+v[i];

    function<int(int)> check=[&](int mid)->int{
        vector<int>dp(n+2);
        priority_queue<PII,vector<PII>,greater<PII>>q;
        q.push({0,0});
        for(int i=1;i<=n+1;i++){
            while(q.size()&&s[i-1]-s[q.top().y]>mid){
                q.pop();
            }
            dp[i]=q.top().x+v[i];
            q.push({dp[i],i});
        }
        if(dp[n+1]<=mid)return 1;
        else return 0;
    };
    int l=0,r=sum+1;
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
    cin>>_;
    while(_--)solve();
    return 0;
}