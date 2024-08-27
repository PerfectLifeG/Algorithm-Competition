#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int mod=998244353;
int book[N];
vector<int>prime;
void get(int n=N-1){
	for(int i=2;i<=n;i++){
		if(!book[i])prime.push_back(i);
		for(int j=0;i*prime[j]<=n;j++){
			book[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void solve(){
	int n;cin>>n;
	unordered_map<int,int>mp;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		for(int j=0;prime[j]*prime[j]<=a;j++){
			if(a%prime[j]==0){
				int cnt=0;
				while(a%prime[j]==0){
					cnt++;
					a/=prime[j];
				}
				mp[prime[j]]=max(cnt,mp[prime[j]]);
			}
		}
		if(a>1)mp[a]=max(1ll,mp[a]);
	}
	int ans=1;
	for(auto i:mp){
		ans*=(i.second+1);
		ans%=mod;
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	get();
	while(_--)solve();
}
