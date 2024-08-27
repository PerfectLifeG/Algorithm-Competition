#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=100010;
int root[N];
int n;
int find(int a){
	if(root[a]==a)return a;
	return root[a]=find(root[a]);
}
void merge(int a,int b){
	int ra=find(a),rb=find(b);
	root[ra]=rb;
}
struct Node
{
	int a,b,c;
	bool operator<(const Node n)const{
		return c<n.c;
	}
}edge[N];
int ans,idx;
void kruskal(){
	for(int i=0;i<=n;i++)root[i]=i;
	sort(edge,edge+idx);
	for(int i=0;i<idx;i++){
		int a=edge[i].a,b=edge[i].b;
		
		if(find(a)!=find(b)){
			merge(a,b);
			ans+=edge[i].c;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c;cin>>c;
		edge[idx++]={0,i,c};
		edge[idx++]={i,0,c};
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int c;cin>>c;
			edge[idx++]={i,j,c};
		}
	}
	kruskal();
	cout<<ans;
	return 0;
}