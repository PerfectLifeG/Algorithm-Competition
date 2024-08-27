#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=1100;
const int mod=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
int dir[4][2]={0,-1,-1,0,0,1,1,0};
char g[N][N];
int book[N][N];
int col[N];
int row[N];
void solve(){
    int n,m;cin>>n>>m;
    PII st,ed;
    for(int i=0;i<n;i++){
    	string s;cin>>s;
    	for(int j=0;j<m;j++){
    		g[i][j]=s[j];
    		if(s[j]=='S'){
    			st={i,j};
    			book[i][j]=2;
    		}
    		if(s[j]=='E'){
    			ed={i,j};
    		}
    	}
    }
    queue<PII>q;
    vector<PII>v;
    q.push(st);
    while(q.size()){
    	auto t=q.front();
		v.push_back(t);
    	q.pop();
    	for(int i=0;i<4;i++){
    		int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
    		if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]||g[tx][ty]=='#')continue;
	    		book[tx][ty]=2;
	    		q.push({tx,ty});
    	}
    }
    sort(all(v));
    for(auto [a,b]:v){
    	row[a]=1;
    	col[b]=1;
    	// cout<<a<<' '<<b<<endl;
    }

    // for(int i=0;i<n;i++){
    // 	for(int j=0;j<m;j++){
    // 		cout<<book[i][j];
    // 	}cout<<endl;
    // }
    // return;

    // if(book[st.x][st.y]==2){yes;return;}
    book[st.x][st.y]=1;
    q.push(st);
    while(q.size()){
    	auto t=q.front();
    	if(t.x==ed.x&&t.y==ed.y){
    		yes;
    		return;
    	}
    	q.pop();
    	for(int i=0;i<4;i++){
    		int tx=t.x+dir[i][0],ty=t.y+dir[i][1];
    		if(tx<0||ty<0||tx>=n||ty>=m||book[tx][ty]==1||(row[tx]!=1&&col[ty]!=1&&g[tx][ty]=='#'))continue;
    		// if(book[tx][ty]==2){
    		// 	yes;
    		// 	return;
    		// }
    		book[tx][ty]=1;
    		q.push({tx,ty});
    	}
    }

    no;

}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}