#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e3+10;
const int INF=0x3f3f3f3f3f3f3f3f;
int dp[N];
void solve(){
	int n;cin>>n;
    vector<int>a(n+1);
    vector<int>s(n+1);
    for(int i=0;i<N;i++)dp[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    int ans=s[n];
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=N-1;j>=0;j--){
        	//dp[i][j]=dp[i-1][j];
        	if(j>=a[i]){
            	if(dp[j-a[i]])dp[j]=1;
			}
            if(dp[j]){
				ans=min(ans,abs(s[n]-j-j));
//				cout<<i<<' '<<j<<endl;
//				cout<<ans<<endl;
			}
            //if(dp[j])cout<<i<<' '<<j<<' '<<dp[j]<<endl;
        }
    }
    cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}
