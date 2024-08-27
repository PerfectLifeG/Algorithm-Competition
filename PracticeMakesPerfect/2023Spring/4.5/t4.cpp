#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define int long long
const int N=1000000,mod=998244353;
int ans[N];
int b[N];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	int mx=0;
	int k;cin>>k;mx=max(mx,k-1);
	for(int i=0;i<k;i++){cin>>b[i];}
		ans[0]=b[0];
	for(int i=0;i<n-1;i++){
		cin>>k;mx=max(mx,k-1);
		for(int j=0;j<k;j++){
			int a;cin>>a;
			int t;
			for(int p=0;p<=mx;p++){
				t=max(t,p+j);
				ans[p+j]+=(b[p]*a%mod)%mod;
			}
			mx=max(mx,t);
		}
	}
	int ret=0;
	for(int i=1;i<=mx;i++){
		ret=(ret+ans[i]*i%mod)%mod;
	}
	cout<<ret;
	return 0;
}