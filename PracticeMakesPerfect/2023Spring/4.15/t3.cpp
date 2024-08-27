#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int n,m,k;
int h[N],e[N],ne[N],idx,w[N];
#define x first
#define y second
void add(int a,int b,int c){
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		queue<pair<int,int>>q;
		int book[N]={0};
		q.push({i,0});
		while(q.size()){
			auto t=q.front();
			q.pop();
			if(t.y==k)
			for(int i=h[t];~i;i=ne[i]){
				int j=e[i];
				if(book[j])continue;
				sum+=w[i];
				q.push({j,t.y+1});
			}
	}
		
	}
	return 0;
}
