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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
char g[20][20];
PII st={-1,-1},ed={-1,-1};
int n,m;
int dir[4][2]={1,0,0,-1,-1,0,0,1};
unordered_map<int,int>mp;
int hs(int a,int b,int c,int d){
	return a*10000000+b*100000+c*1000+d;
}
int dfs(int x,int y,int key,int body){
	if(x==ed.x&&y==ed.y){
		return 1;
	}
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if(tx<0||ty<0||tx>=n||ty>=m||g[tx][ty]=='w')continue;
		if(g[tx][ty]=='d'&&key&&body&&!mp.count(hs(tx,ty,key-1,body-1))){
			mp[hs(tx,ty,key-1,body-1)]=1;
			if(dfs(tx,ty,key-1,body-1))return 1;
		}
		if(g[tx][ty]!='d'&&body&&!mp.count(hs(tx,ty,key,body-1))){
			mp[hs(tx,ty,key,body-1)]=1;
			if(dfs(tx,ty,key,body-1))return 1;
		}
	}
	return 0;
}
void solve(){
    int p,k;
    cin>>n>>m>>p>>k;
    for(int i=0;i<n;i++){
    	string s;cin>>s;
    	for(int j=0;j<m;j++){
    		g[i][j]=s[j];
    		if(s[j]=='s'){
    			st={i,j};
    		}
    		if(s[j]=='e'){
    			ed={i,j};
    		}
    	}
    }
    if(st.x==-1&&st.y==-1||ed.x==-1&&ed.y==-1){
    	no;
    	return;
    }
    mp[hs(st.x,st.y,k,p)]=1;
    if(dfs(st.x,st.y,k,p))yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}