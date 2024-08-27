#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
struct Node
{
	int s;
	int a;
	int b;
	int c;
	int d;
	int e;
	string ss;
}node[N];
int cmp(Node a,Node b){
	if(a.s==b.s){
		if(a.a==b.a){
			if(a.b==b.b){
				if(a.c==b.c){
					if(a.e==b.e){
						if(a.d==b.d){
							return a.ss<b.ss;
						}
						return a.d>b.d;
					}
					return a.e>b.e;
				}
				return a.c>b.c;
			}
			return a.b>b.b;
		}
		return a.a>b.a;
	}
	return a.s>b.s;
}
signed main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		node[i].ss=s;
		for(int j=0;j<5;j++){
			int a;cin>>a;
			node[i].s+=a;
			if(j==0)node[i].a=a;
			if(j==1)node[i].b=a;
			if(j==2)node[i].c=a;
			if(j==3)node[i].d=a;
			if(j==4)node[i].e=a;
		}
	}
	sort(node,node+n,cmp);
	for(int i=0;i<n;i++){
		cout<<node[i].ss<<endl;
	}
	return 0;
}