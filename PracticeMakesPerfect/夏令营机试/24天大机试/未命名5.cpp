#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,k;
vector<int>nums;
unordered_map<int,int>book;
int hs(int i,int is_num,int limit){
	return 100*i+10*is_num+limit;
}

int dfs(int i,int is_num,int limit){
	if(i==-1){
		return is_num;
	}
	if(book[hs(i,is_num,limit)])return book[hs(i,is_num,limit)];
	int res=0;
	if(!is_num)res+=dfs(i-1,0,0);
	
	int up=9;
	if(limit)up=nums[i];
	for(int j=1-is_num;j<=up;j++){
		if(j<k){
			if(j==up)res+=dfs(i-1,1,limit);
			else res+=dfs(i-1,1,0);
		}
	}
	book[hs(i,is_num,limit)]=res;
	return res;
}
void solve(){
	cin>>n>>k;
	nums.clear();book.clear();
	while(n){nums.push_back(n%10);n/=10;}
	cout<<dfs(nums.size()-1,0,1)<<endl;
}
signed main(){
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);

	int _;cin>>_;
	while(_--)solve();
} 
