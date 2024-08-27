#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=100010;
#define lowbit(x) x&-x
int tr[N],a[N];
int s[8010][8010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]<a[i])s[i][j]++;
		}
	}
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=n;j++){
			s[i][j]+=s[i+1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]+=s[i][j-1];
		}
	}
	for(int i=0;i<q;i++){
		int a,b;cin>>a>>b;
		cout<<s[a][b]<<endl;
	}
	return 0;
}