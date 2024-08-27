#include<bits/stdc++.h>
using namespace std;
const int N=3010;
int x1,x2,yy1,y2;
int n,m;
int cnt=0;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
typedef pair<int,int> PII;
#define x first
#define y second
deque<PII>q;
int book[N][N];
int g[N][N];
void bfs(){
	while(q.size()){
		auto t1=q.front();
		auto t2=q.back();
		q.pop_front();
		q.pop_back();
		cnt++;
		for(int i=0;i<4;i++){
			int tx=t1.x+dir[i][0],ty=t1.y+dir[i][1];
			// cout<<tx<<' '<<ty<<endl; 
			if(tx<1||tx>n||ty<1||ty>m)continue;
			if(g[tx][ty]){return;}
			q.push_front({tx,ty});
			book[tx][ty]=1;
		}
		for(int i=0;i<4;i++){
			int tx=t2.x+dir[i][0],ty=t2.y+dir[i][1];
			if(tx<1||tx>n||ty<1||ty>m)continue;
			if(book[tx][ty]){return;}
			q.push_back({tx,ty});
			g[tx][ty]=1;
		}
	}
}
int main(){
	cin>>n>>m;
	cin>>x1>>yy1>>x2>>y2;
	q.push_back({x2,y2});
	q.push_front({x1,yy1});
	book[x1][yy1]=1;
	g[x2][y2]=1;
	bfs();
	cout<<cnt;
	return 0;
}