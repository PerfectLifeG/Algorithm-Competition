#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n;
int a[N][N];
int main(){
	while(cin>>n){
		vector<pair<int,int> >v;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				v.push_back({a[i][j],i*n+j});
			}
		}
		sort(v.begin(),v.end());
		int idx=v.size()-1;
		for(int i=v.size()-2;i>=0;i--){
			if(v[i].first!=v[idx].first)break;
			else idx=i;
		}
		swap(a[v[0].second/n][v[0].second%n],a[0][0]);
		swap(a[v[1].second/n][v[1].second%n],a[0][n-1]);
		swap(a[v[2].second/n][v[2].second%n],a[n-1][0]);
		swap(a[v[3].second/n][v[3].second%n],a[n-1][n-1]);
		swap(a[v[idx].second/n][v[idx].second%n],a[n/2][n/2]);
		for(int i=0;i<n;i++){
			cout<<a[i][0];
			for(int j=1;j<n;j++){
				cout<<' '<<a[i][j]; 
			}
			cout<<endl;
		} 
//		cout<<endl;
	}
	return 0;
}
