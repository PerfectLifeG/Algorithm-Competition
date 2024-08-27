#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
int root[N];
int book[N];
int find(int a){
	if(a==root[a])return a;
	return root[a]=find(root[a]);
}
void merge(int a,int b){
	int ra=find(a),rb=find(b);
	root[ra]=rb;
}
signed main(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)root[i]=i;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		if(find(a)!=find(b)){
			merge(a,b);
		}
	}
	int mn=1e16;
	for(int i=1;i<=n;i++){
		book[root[find(i)]]++;
	}
	int ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(book[i]){
			ans++;
			mn=min(mn,book[i]);
			cnt+=book[i];
		}
	}
	if(ans==1){cout<<0;return 0;}
	cout<<n+(max(0ll,ans-2))*mn;
	return 0;
}