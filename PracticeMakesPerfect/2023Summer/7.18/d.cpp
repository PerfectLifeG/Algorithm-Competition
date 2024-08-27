#include <bits/stdc++.h>
using namespace std;
#define M 100500
const int N=200010;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int qk(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int inv(int a)
{
    return qk(a,mod-2);
}
vector<int > vec[M];
int vis[M],dp[M];
int dfs(int x){
    if(dp[x]!=-1)return dp[x];
    vis[x]=1;
    dp[x]=0;
    for(int i=0;i<vec[x].size();i++){
        if(!vis[vec[x][i]])
        dp[x]^=dfs(vec[x][i])+1;
    }
    return dp[x];
}
int main(){
    int tcase,n,i,s,e;
    scanf("%d",&tcase);
    while(tcase--){
        scanf("%d",&n);
        for(i=0;i<=n;i++)vec[i].clear();
        for(int i=0;i<=n;i++){
        	vis[i]=0;
        	dp[i]=-1;
        }
        // memset(vis,0,sizeof(vis));
        // memset(dp,-1,sizeof(dp));
        for(i=0;i<n-1;i++){
            scanf("%d%d",&s,&e);
            vec[s].push_back(e);
            vec[e].push_back(s);
        }
        int a=0,b=0;
        for(int i=1;i<=n;i++){
        	for(int j=0;j<=n;j++){
	        	vis[j]=0;
	        	dp[j]=-1;
	        }
        	if(dfs(i))a++;
        	else b++;
        }
        // for(int i=1;i<=n;i++){
        // 	if(dp[i])a++;
        // 	else b++;
        // }
        cout<<a<<" "<<b<<endl;
        // // cout<<a*inv(b)<<endl;
        printf("%d\n",a*inv(b));
    }
    return 0;
}