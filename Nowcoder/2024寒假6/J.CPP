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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    string s;cin>>s;s=' '+s;
    vector<int>v[n+1];
    for(int i=2;i<=n;i++){
        int a;cin>>a;
        v[a].push_back(i);
    }
    vector<int>ans(n+1,1);
    int flag=1;
    function<int(int)> dfs=[&](int t)->int{
        int sum=1;
        int son=t;
        for(auto j:v[t]){
            int p=dfs(j);
            if(s[j]=='W'){
                sum+=p;
                son=j;
            }
        }
        if(s[t]=='W'){
            return sum+1;
        }else{
            if(sum%3==2){
                ans[t]=2;
            }else if(sum%3==1){
                if(sum==1)flag=0;
                ans[son]=2;
                ans[t]=2;
            }
            return 0;
        }
    };

    dfs(1);
    if(flag){
        for(int i=1;i<=n;i++)cout<<ans[i];cout<<endl;
    }else cout<<"-1\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}