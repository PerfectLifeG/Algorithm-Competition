#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair<int,int>
const int INF=1e9;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<PII>v1[n+1];
	vector<PII>v2[n+1];
	for(int i=0;i<m;i++){
		int a,b,c,x;cin>>a>>b>>c>>x;
		v2[a].push_back({b,c});
		v2[b].push_back({a,c});
		if(x==0){
			v1[a].push_back({b,c});
			v1[b].push_back({a,c});
		}
	}
	
	vector<int>book1(n+1);
	vector<int>d1(n+1,INF);d1[1]=0;
	priority_queue<PII,vector<PII>,greater<PII>>q1;
	q1.push({0,1});
	while(q1.size()){
		PII a=q1.top();
		q1.pop();
		int dist=a.first,t=a.second;
		if(book1[t])continue;
		book1[t]=1;
		for(int i=0;i<v1[t].size();i++){
			int j=v1[t][i].first;
			int w=v1[t][i].second;
			if(book1[j])continue;
			if(d1[j]>w+dist){
				d1[j]=w+dist;
				q1.push({d1[j],j});
			}
		}
	}
	
	
	vector<int>book2(n+1);
	vector<int>d2(n+1,INF);d2[k]=0;
	priority_queue<PII,vector<PII>,greater<PII>>q2;
	q2.push({0,k});
	while(q2.size()){
		PII a=q2.top();
		q2.pop();
		int dist=a.first,t=a.second;
		if(book2[t])continue;
		book2[t]=1;
		for(int i=0;i<v2[t].size();i++){
			int j=v2[t][i].first;
			int w=v2[t][i].second;
			if(book2[j])continue;
			if(d2[j]>w+dist){
				d2[j]=w+dist;
				q2.push({d2[j],j});
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<d1[i]<<' ';
//	}cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<d2[i]<<' ';
//	}
	
	int ans=INF;
	ans=min(ans,d1[n]);
	ans=min(ans,d2[n]+d1[k]);
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
	
}
signed main(){
	int T;cin>>T;
	while(T--)solve();
} 
