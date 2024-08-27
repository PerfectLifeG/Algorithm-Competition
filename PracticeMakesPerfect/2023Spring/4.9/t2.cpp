#include<bits/stdc++.h>
using namespace std;
const int N=1100;
int f[N][N];
int cnt0,cnt1;int n,m;
void check(int a,int b){
	if((a-1==-1||a-1>=0&&f[a-1][b]!=f[a][b])&&(a+1==n||a+1<n&&f[a+1][b]!=f[a][b])
		&&(b-1==-1||b-1>=0&&f[a][b-1]!=f[a][b])&&(b+1==m||b+1<m&&f[a][b+1]!=f[a][b]))
	{
		// cout<<a<<' '<<b<<' '<<f[a][b]<<endl;
		if(f[a][b])cnt1++;
		else cnt0++;
	}
	
}
int main(){
	cin>>n>>m;
	if(n==1&&m==1){cout<<0;return 0;}
	for(int i=0;i<n;i++){
		string s;cin>>s;
		for(int j=0;j<m;j++){
			f[i][j]=s[j]-'0';
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			check(i,j);
		}
	}
	// cout<<cnt0<<endl<<cnt1<<endl;
	if(cnt0>cnt1)cout<<cnt0-cnt1;
	else if(cnt1>cnt0)cout<<cnt1-cnt0;
	else cout<<0;
	return 0;
}