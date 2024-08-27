#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int dp[N];
int manercher(string t){
	string s="$#";
	for(int i=0;i<t.size();i++)s+=t[i],s+='#';
	s+='^';
	//cout<<s<<endl;
	int r=0,mid=0;
	for(int i=0;i<s.size();i++){
		if(i<r)dp[i]=min(dp[mid*2-i],r-i+1);
		else dp[i]=1;
		while(s[i-dp[i]]==s[i+dp[i]])dp[i]++;
		if(i+dp[i]>r){
			mid=i;
			r=i+dp[i]-1;
		}
	}
	int ans=0;
	for(int i=0;i<s.size();i++){
		ans=max(ans,dp[i]-1);
	}
	return ans;
}
void solve(){
	string s;cin>>s;
	cout<<manercher(s)<<endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--)solve();
}
