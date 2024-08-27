#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
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
int inv(int v)
{
	return qk(v,mod-2);
}
void solve(){
	int n;cin>>n;
	if(n==1){
		cout<<0<<endl;
		return;
	}
	cout<<(2*n-1)*inv(3)%mod<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}