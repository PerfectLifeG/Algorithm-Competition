#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;cin>>n;
	vector<int>a(n);
	map<int,int>mp;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	auto i=mp.begin();auto j=mp.begin();j++;
	int mx=i->second;
	for(;j!=mp.end();i++,j++){
		if(mx<j->second){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}