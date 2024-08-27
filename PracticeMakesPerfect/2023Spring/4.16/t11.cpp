#include<bits/stdc++.h>
using namespace std;
const int N=200100;
int h[N],e[N],ne[N],idx2;
int fa[N];
int sum[N];
void add(int a,int b){
	e[idx2]=b;
	ne[idx2]=h[a];
	h[a]=idx2++;
}
int dfs(int t){
//	cout<<t<<' '<<h[t]<<endl;
	for(int i=h[t];~i;i=ne[i]){
		int j=e[i];
		sum[t]+=dfs(j);
//		cout<<t<<' '<<sum[t]<<endl;
	}
	return sum[t];
}
int main(){
	unordered_map<string,int>mp;
//	unordered_map<int,string>mp2;
	memset(h,-1,sizeof h);
	int n,m;cin>>n>>m;
	int idx=1;
	for(int i=0;i<m;i++){
		string a,b;cin>>a>>b;
		if(!mp.count(a))mp[a]=idx++;
		if(!mp.count(b))mp[b]=idx++;
		if(a[0]<='9'&&a[0]>='0')sum[mp[a]]=1;
		add(mp[b],mp[a]);
		fa[mp[a]]=mp[b];
	}
//	for(int i=1;i<idx;i++)cout<<sum[i]<<' '<<fa[i]<<endl;
	int root;
	for(int i=1;i<idx;i++){
		if(!fa[i]){
			root=i;
			break;
		}
	}
//	cout<<root;
	fa[root]=-1;
	dfs(root);
	
//	return 0;
	char op[2];
	while(m--){
		cin>>op;
		if(*op=='Q'){
			string a;cin>>a;
			if(!mp.count(a)){
			cout<<0<<endl;continue;}
			cout<<sum[mp[a]]<<endl;
		}else if(*op=='T'){
			string a,b;cin>>a>>b;
			if(!mp.count(a)){
				mp[a]=idx++;
				if(!mp.count(b)){
					mp[b]=idx++;
					fa[mp[a]]=mp[b];
					sum[mp[b]]=1;
					fa[mp[b]]=-1;
					continue;
				}
				fa[mp[a]]=mp[b];
				int ida=fa[mp[a]];
				while(1){
					sum[ida]++;
					if(fa[ida]==-1)break;
					ida=fa[ida];
				}
				continue;
			}
			if(!mp.count(b)){
				mp[b]=idx++;
				fa[mp[a]]=mp[b];
				sum[mp[b]]=1;
				fa[mp[b]]=-1;
				continue;
			}
			int ida=fa[mp[a]],idb=mp[b];
			while(1){
				sum[ida]--;
				if(fa[ida]==-1)break;
				ida=fa[ida];
			}
			while(1){
				sum[idb]++;
				if(fa[idb]==-1)break;
				idb=fa[idb];
			}
			fa[mp[a]]=mp[b];
		}else break;
	}
	return 0;
}
