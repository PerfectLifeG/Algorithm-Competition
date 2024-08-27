#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int v[20010];
int book[400][20010];
unordered_map<int,int>mp;
int idx;
int main(){
	
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	
	for(int j=0;j<27;j++){
		int x=(1<<j);
		for(int k=1;k<=n;k++){
			if((v[k]&x)==x){
				book[idx][k]++;
			}
		}
		mp[x]=idx++;
	}
	
	for(int i=0;i<27;i++){
		for(int j=i+1;j<27;j++){
			int x=(1<<i)+(1<<j);
			for(int k=1;k<=n;k++){
				if((v[k]&x)==x){
					book[idx][k]++;
				}
			}
			mp[x]=idx++;
		}
	}
	
	for(int i=0;i<400;i++){
		for(int j=1;j<20010;j++){
			book[i][j]+=book[i][j-1];
		}
	}
	
	int q;scanf("%d",&q);
	while(q--){
		int l,r,x;
		scanf("%d %d %d",&l,&r,&x);
		
		if(mp.count(x)){
			int t=mp[x];
			printf("%d\n",book[t][r]-book[t][l-1]);
		}else printf("0\n");
		
	}
} 
