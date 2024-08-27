#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
void solve() {
	int n;cin>>n;
	int a;cin>>a;
	int d=a;
	int s=a;
	for(int i=1; i<n-1; i++) {
		int b;
		cin>>b;
		d=__gcd(b,a);
		a=a*b/d;
	}
	int b;cin>>b;
	int ans=1;
	map<int,int>mp;
	for(int j=2; j<=a/j; j++) {
		if(a%j==0) {
			int cnt=0;
			while(a%j==0) {
				cnt++;
				a/=j;
			}
			mp[j]+=cnt;
		}
	}
	if(a>1)mp[a]+=1;
	for(int j=2; j<=b/j; j++) {
		if(b%j==0) {
			int cnt=0;
			while(b%j==0) {
				cnt++;
				b/=j;
			}
			if(mp.count(j))mp[j]=max(mp[j],cnt);
			else mp[j]+=cnt;
		}
	}
	if(b>1) {
		if(mp.count(b))mp[b]=max(mp[b],1ll);
		else mp[b]+=1;
	}
	for(auto i:mp) {
		ans*=(i.second+1);
		ans%=mod;
	}
	cout<<ans<<endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}
