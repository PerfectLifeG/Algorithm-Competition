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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<PII>v;
    vector<int>val(n+2);
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        v.push_back({l,r});
        val[l]++;val[r+1]--;
    }
    sort(all(v),[&](PII a,PII b){
        if(a.x!=b.x)return a.x<b.x;
        return a.y>b.y;
    });
    for(int i=1;i<=n;i++){
        val[i]+=val[i-1];
    }

    vector<PII>tmp;
    for(int i=0;i<v.size();){
        tmp.push_back(v[i]);
        int j=i+1;
        while(j<v.size()&&v[j].x>=v[i].x&&v[j].y<=v[i].y)j++;
        i=j;
    }
    vector<int>L(n+1);
    for(int i=1;i<=n;i++)L[i]=i;
    int j=1;
    for(int i=0;i<tmp.size();i++){
        while(j<tmp[i].x){
            L[j]=1;
            j++;
        }
        while(j<=tmp[i].y){L[j]=tmp[i].x;j++;}
    }
    
    int dp[n+1]={};
    for(int i=1;i<=n;i++)dp[i]=max(dp[i-1],dp[L[i]-1]+val[i]);
    cout<<dp[n]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}