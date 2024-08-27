#include<bits/stdc++.h>
using namespace std;
int g[N][N];
int main(){
	int n,m,t;cin>>n>>m>>t;
	int x,y;
	for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++){
			cin>>g[i][j];
			if(g[i][j]<0){
				x=i;
				y=j;
			}
			else g[i][j]++;
		}
	}
	cout<<0;
	return 0;
}
