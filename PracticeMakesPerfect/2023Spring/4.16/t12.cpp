#include<bits/stdc++.h>
using namespace std;
const int N=510;
char a[N];
int d[N][N];
int main(){
	int n;cin>>n;
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int m;cin>>m;
		for(int j=0;j<m;j++){
			int num,dis;
			scanf("%d:%d",&num,&dis);
//			cout<<num<<' '<<dis<<endl;
			d[i][num]=dis;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j){
				d[i][j]=0;
				break;
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	vector<pair<int,int>>ans1;
	vector<pair<int,int>>ans2;
	int a1=0x3f3f3f3f,a2=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=1;j<=n;j++){
			if(a[j]!=a[i]){
				mx=max(mx,d[j][i]);
			}
		}
		if(a[i]=='F'){
			ans1.push_back({mx,i});
		}else {
			ans2.push_back({mx,i});
		}
	}
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	cout<<ans1[0].second;
	for(int i=1;i<ans1.size();i++){
		if(ans1[i].first!=ans1[0].first)break;
		cout<<' '<<ans1[i].second;
	}
	cout<<endl;
	cout<<ans2[0].second;
	for(int i=1;i<ans2.size();i++){
		if(ans2[i].first!=ans2[0].first)break;
		cout<<' '<<ans2[i].second;
	}
	cout<<endl;
	return 0;
}
