#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef pair<int,int> PII;
struct Node
{
	int x,y,z;
};
Node t[N];
vector<int>v[N];
vector<int>v2[N];
int book[N];
void bfs(int n){
	queue<int>q;
	q.push(n);
	while(q.size()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<v[t].size();i++){
			int j=v[t][i];
			if(book[j]!=0&&book[j]>=book[t]+1){
				continue;
			}
			book[j]=book[t]+1;
			q.push(j);
		}
	}
}
void bfs2(int n){
	queue<int>q;
	q.push(n);
	while(q.size()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<v2[t].size();i++){
			int j=v2[t][i];
			if(book[j]!=0&&book[j]<=book[t]-1){
				continue;
			}
			book[j]=book[t]-1;
			q.push(j);
		}
	}
}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].x>>t[i].y>>t[i].z;
		if(i>2&&!((t[i].x>t[2].x&&t[i].y>t[2].y&&t[i].z>t[2].z||t[i].x>t[1].x&&t[i].y>t[1].y&&t[i].z>t[1].z)||
			(t[i].x<t[2].x&&t[i].y<t[2].y&&t[i].z<t[2].z||t[i].x<t[1].x&&t[i].y<t[1].y&&t[i].z<t[1].z))){
			book[i]=10000;
		}
	}
	if(t[2].x>t[1].x&&t[2].y>t[1].y&&t[2].z>t[1].z||t[2].x<t[1].x&&t[2].y<t[1].y&&t[2].z<t[1].z){
		cout<<-1<<endl;return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(t[i].x>t[j].x&&t[i].y>t[j].y&&t[i].z>t[j].z&&
				(t[j].x>=t[2].x&&t[j].y>=t[2].y&&t[j].z>=t[2].z||t[j].x>=t[1].x&&t[j].y>=t[1].y&&t[j].z>=t[1].z))
			{
				v[j].push_back(i);
				// cout<<j<<' '<<i<<endl;
			}else if(t[i].x<t[j].x&&t[i].y<t[j].y&&t[i].z<t[j].z&&
				(t[j].x<=t[2].x&&t[j].y<=t[2].y&&t[j].z<=t[2].z||t[j].x<=t[1].x&&t[j].y<=t[1].y&&t[j].z<=t[1].z))
			{
				v2[j].push_back(i);
				// cout<<j<<' '<<i<<endl;
			}
		}
	}
	book[1]=10000;
	book[2]=10000;
	bfs(1);
	// for(int i=1;i<=n;i++)cout<<book[i]<<' ';cout<<endl;
	bfs2(1);
	// for(int i=1;i<=n;i++)cout<<book[i]<<' ';cout<<endl;
	bfs(2);
	// for(int i=1;i<=n;i++)cout<<book[i]<<' ';cout<<endl;
	bfs2(2);
	// for(int i=1;i<=n;i++)cout<<book[i]<<' ';cout<<endl;
	map<int,int>mp;
	for(int i=1;i<=n;i++)mp[book[i]]=1;
	if(mp.size()>256){
		cout<<-1<<endl;
		return;
	}
	int ans=0;
	for(auto i:mp)mp[i.first]=ans++;
	for(int i=1;i<=n;i++){
		cout<<mp[book[i]]<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	// cin>>_;
	while(_--)solve();
}