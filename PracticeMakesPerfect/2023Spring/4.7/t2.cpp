#include<bits/stdc++.h>
using namespace std;
const int N=100;
int f[N][N];
int main(){
	int n;cin>>n;
	int flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		if(!flag1)break;
		for(int j=1;j<=n;j++){
			if(f[j][i]!=f[i][j]){flag1=0;break;}
		}
	}
	for(int i=1;i<=n;i++){
		if(!flag2)break;
		for(int j=n-1;j>=0;j--){
			if(f[n-j+1][i]!=f[i][j]){flag2=0;break;}
		}
	}
	if(flag1&&flag2)cout<<3;
	else if(flag1&&!flag2)cout<<1;
	else if(!flag1&&flag2)cout<<2;
	else cout<<0;
	return 0;
}