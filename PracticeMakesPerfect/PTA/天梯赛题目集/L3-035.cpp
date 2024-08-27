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
    vector<int>v[n+1];
    vector<int>cost(n+1);
    vector<int>col(n+1);
    for(int i=1;i<=n;i++){
        cin>>col[i]>>cost[i];
        int k;cin>>k;
        for(int j=0;j<k;j++){
            int a;cin>>a;
            v[i].push_back(a);
        }
    }

    // vector<vector<int>> dp(n+1,vector<int>(3,INF));
    int dp[n+1][3]={};
    int cnt[n+1];
    function<int(int)> dfs=[&](int t)->int{
        cnt[t]=1;
        vector<int>son;
        int equ=0;
        for(auto j:v[t]){
            cnt[t]+=dfs(j);
            if(cnt[j]&1){
                son.push_back(j);
            }else equ+=dp[j][0];
        }
        // cout<<t<<endl;
        // for(auto i:son){
        //     cout<<i<<' ';
        // }cout<<endl;
        if(son.size()&1){
            int sum=0;
            //黑多
            sort(all(son),[&](int a,int b){
                return dp[a][2]-dp[a][1]<dp[b][2]-dp[b][1];
            });
            for(int i=0;i<son.size();i++){
                sum+=dp[son[i]][1];
                if(i<son.size()/2)sum+=dp[son[i]][2]-dp[son[i]][1];
            }
            if(col[t]==0){//白
                dp[t][0]=equ+sum;
            }else dp[t][0]=equ+sum+cost[t];
            //白多
            sum=0;
            sort(all(son),[&](int a,int b){
                return dp[a][1]-dp[a][2]<dp[b][1]-dp[b][2];
            });
            for(int i=0;i<son.size();i++){
                sum+=dp[son[i]][2];
                if(i<son.size()/2)sum+=dp[son[i]][1]-dp[son[i]][2];
            }
            if(col[t]==1){//黑
                dp[t][0]=min(dp[t][0],equ+sum);
            }else dp[t][0]=min(dp[t][0],equ+sum+cost[t]);
        }else if(son.size()){
            //黑多
            // cout<<t<<' '<<col[t]<<' '<<cost[t]<<endl;
            int sum=0;
            sort(all(son),[&](int a,int b){
                return dp[a][2]-dp[a][1]<dp[b][2]-dp[b][1];
            });
            for(int i=0;i<son.size();i++){
                sum+=dp[son[i]][1];
                if(i<son.size()/2-1)sum+=dp[son[i]][2]-dp[son[i]][1];
            }
            if(col[t]==0){//白
                dp[t][1]=equ+sum;
            }else dp[t][1]=equ+sum+cost[t];

            //白多
            sum=0;
            sort(all(son),[&](int a,int b){
                return dp[a][1]-dp[a][2]<dp[b][1]-dp[b][2];
            });
            for(int i=0;i<son.size();i++){
                sum+=dp[son[i]][2];
                if(i<son.size()/2-1)sum+=dp[son[i]][1]-dp[son[i]][2];
            }
            if(col[t]==1){//黑
                dp[t][2]=equ+sum;
            }else dp[t][2]=equ+sum+cost[t];
            // cout<<dp[t][1]<<endl;
            // cout<<dp[t][2]<<endl;

            //相等
            sum=0;
            sort(all(son),[&](int a,int b){
                return dp[a][1]-dp[a][2]<dp[b][1]-dp[b][2];
            });
            for(int i=0;i<son.size();i++){
                sum+=dp[son[i]][2];
                if(i<son.size()/2)sum+=dp[son[i]][1]-dp[son[i]][2];
            }
            // cout<<t<<' '<<sum<<endl;
            if(col[t]==1){
                dp[t][1]=min(dp[t][1],equ+sum);
                dp[t][2]=min(dp[t][2],equ+sum+cost[t]);
            }else {
                dp[t][1]=min(dp[t][1],equ+sum+cost[t]);
                dp[t][2]=min(dp[t][2],equ+sum);
            }
        }else{
            if(col[t]==1){
                dp[t][1]=equ;
                dp[t][2]=equ+cost[t];
            }else {
                dp[t][1]=equ+cost[t];
                dp[t][2]=equ;
            }
        }
        // cout<<t<<' '<<cnt[t]<<' '<<dp[t][0]<<' '<<dp[t][1]<<' '<<dp[t][2]<<endl;
        return cnt[t];
    };
    dfs(1);
    if(cnt[1]&1){
        cout<<min({dp[1][1],dp[1][2]})<<endl;
    }else cout<<dp[1][0]<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}