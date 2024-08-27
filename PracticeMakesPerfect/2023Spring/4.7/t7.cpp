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
	for(int i=1;i<=n;i++){
		book[root[i]]++;
	}
	sort(book+1,book+n+1);
	int ans=0;
	int j;
	for(int i=1;i<=n;i++){
		if(book[i]){
			j=i;
			break;
		}
	}
	for(int i=j+1;i<=n;i++){
		ans+=book[i];
	}
	cout<<ans+(n-j-1)*book[j];
	return 0;
}