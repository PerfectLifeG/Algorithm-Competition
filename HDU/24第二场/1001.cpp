//#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <set>
#include <stack>
#include <bitset>

//#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define lowbit(x) x&(-x)
//#define x first
//#define y second;
using namespace std;

const int N = 3500;
const int mod = 1e9+7;
const double eps = 1e-9;

//----------------------------------------------------------------------


//-----------------------------------------------------------------------

void solve(){
	int n; cin>>n;
	vector<int> now(n/3+1);
	vector<vector<int>> vis(n/3+1,vector<int>(n/3+1));
	vector<pii> ans;
	for(int i=1;i<=n/3;++i){
		int cnt=3;
		now[i]=i+1;
		for(int j=1;j<i&&cnt;++j){
			if(vis[j][i]){
				if(now[j]<=n/3)vis[j][now[j]]=1;
				ans.pb({j,now[j]++});
				// cout<<j<<' '<<now[j]-1<<endl;
				cnt--;
			}
			if(ans.size()==n)break;
		}
		if(ans.size()==n)break;
		while(cnt){
			if(ans.size()==n)break;
			if(now[i]<=n/3)vis[i][now[i]]=1;
			ans.pb({i,now[i]++});
			// cout<<i<<' '<<now[i]-1<<endl;
			cnt--;
		}
		if(ans.size()==n)break;
	}
	cout<<endl;
	sort(all(ans));
	for(auto [x,y]:ans)cout<<x<<' '<<y<<endl;
}

signed main()
{
	IOS
	int _ = 1;
	cin>>_;
	while(_--) solve();
    return 0;
}
