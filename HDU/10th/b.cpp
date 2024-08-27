#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int>mp;
unordered_map<int,int>mp2;
void solve(){
	int n;cin>>n;
	vector<int>a((1<<n));
	mp.clear();mp2.clear();
	for(int i=1;i<=(1<<n)-1;i++)cin>>a[i],mp[a[i]]++;
	sort(a.begin()+1,a.end());
	vector<int>ans;
	for(int i=1;i<(1<<n);i*=2){
		ans.push_back(a[i]);
		mp2[a[i]]++;
	}
	// 0 0 0 1 1 1 1
	//0 0 1
	// for(auto i:ans)cout<<i<<' ';cout<<endl;
	vector<int>t;
	for(int i=0;i<ans.size();i++){
		for(auto j:t){
			mp2[j^ans[i]]++;
			t.push_back(j^ans[i]);
			// cout<<ans[i]<<' '<<(j^ans[i])<<endl;
		}
		t.push_back(ans[i]);
	}
	// for(auto i:t)cout<<i<<' ';cout<<endl;
	for(auto i:mp2){
		if(i.second!=mp[i.first]){
			cout<<"-1"<<endl;
			return;
		}
	}
	for(auto i:ans)cout<<i<<' ';
	cout<<endl;
}
signed main(){
	freopen("output.txt","r",stdin);
	freopen("b.txt","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}