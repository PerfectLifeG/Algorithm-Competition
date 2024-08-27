#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=1000;
char s[N][N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	int flag1=1,flag2=1;
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++){
		if(!flag1)break;
		for(int j=0;j<m/2;j++){
			if(s[i][j]!=s[i][m-1-j]){flag1=0;break;}
		}
	}
	for(int i=0;i<n/2;i++){
		if(!flag2)break;
		for(int j=0;j<m;j++){
			if(s[i][j]!=s[n-1-i][j]){flag2=0;break;}
		}
	}
	if(flag1&&flag2){
		cout<<"LRUD";
	}else if(flag1){
		cout<<"LR";
	}else if(flag2)cout<<"UD"; 
	else cout<<"NO";
	return 0;
}