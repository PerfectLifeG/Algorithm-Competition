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
// const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int N,K,P;
vector<int>ans;
vector<int>tmp;
int s=0;
void dfs(int t,int cnt,int now,int sum){
    // cout<<t<<' '<<cnt<<' '<<now<<' '<<sum<<endl;
    if(now+K-cnt>N)return;
    if(cnt==K){
        if(now==N){
            if(sum>s){
                s=sum;
                ans=tmp;
            }
        }
        return;
    }
    for(int i=t;i>=1;i--){
        tmp.push_back(i);
        dfs(i,cnt+1,now+pow(i,P),sum+i);
        tmp.pop_back();
    }
}
void solve(){
    cin>>N>>K>>P;
    dfs(pow(N-(K-1),1.0/P),0,0,0);
    if(!ans.size())cout<<"Impossible\n";
    else{
        cout<<N<<" = "<<ans[0]<<'^'<<P;
        for(int i=1;i<ans.size();i++){
            cout<<" + "<<ans[i]<<'^'<<P;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}