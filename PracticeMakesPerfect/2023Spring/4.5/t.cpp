#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
// #define int long long
const int N=12,M=1<<N;
vector<int>state;
vector<int>head[M];
int f[N][M];
int n,m;
int book[M];
int check(int x){
	return 1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	while(cin>>n>>m,n||m){
		for(int i=0;i<1<<n;i++){
			if(check(i)){
				state.emplace_back(i);
			}
		}

	}
	return 0;
}