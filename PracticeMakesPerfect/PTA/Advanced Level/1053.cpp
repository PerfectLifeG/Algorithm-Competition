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
int cmp(vector<int>a, vector<int>b){
    int n=min(a.size(),b.size());
    for(int i=0;i<n;i++){
        if(a[i]>b[i])return 1;
        else if(a[i]<b[i])return 0;
    }
    return 0;
}
void solve(){
    int n,m,s;cin>>n>>m>>s;
    vector<int>val(n);
    vector<int>v[n];
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<m;i++){
        int a;int k;cin>>a>>k;
        for(int j=0;j<k;j++){
            int b;cin>>b;
            v[a].push_back(b);
        }
    }
    vector<vector<int>>ans;
    vector<int>temp;
    function<void(int,int,int)> dfs=[&](int t,int fa,int sum){
        int flag=1;
        temp.push_back(val[t]);
        for(auto j:v[t]){
            if(j==fa)continue;
            flag=0;
            dfs(j,t,sum+val[j]);
            temp.pop_back();
        }
        if(flag&&sum==s)ans.push_back(temp);
    };
    dfs(0,-1,val[0]);
    sort(all(ans),cmp);
    for(auto i:ans){
        int first=1;
        for(auto j:i){
            if(first){cout<<j;first=0;}
            else cout<<' '<<j;
        }
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}