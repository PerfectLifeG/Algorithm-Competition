#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=100;
int a[N][N];
int s[N][N];
int book[100000];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int i2=i;i2<=n;i2++)
				for(int j2=j;j2<=m;j2++){
					book[s[i2][j2]+s[i-1][j-1]-s[i2][j-1]-s[i-1][j2]]++;
				}
		
	for(int i=0;i<=n*m;i++){
		cout<<book[i]<<endl;
	}
	return 0;
}