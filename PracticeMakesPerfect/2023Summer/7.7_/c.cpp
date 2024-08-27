#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
int a[N];
int s[N];
struct Node{
	int a;
	int b;
	int id;
	bool operator<(const Node& n)const
	{
		if(a==n.a){
			if(b==n.b)return id<n.id;
			return b<n.b;
		}
		return a>n.a;
	}
}node[N];
void solve()
{
 	int n,m,h;cin>>n>>m>>h;
 	int idx=0;
 	for(int i=0;i<n;i++){
 		for(int j=1;j<=m;j++){
 			cin>>a[j];
 		}
 		sort(a+1,a+m+1);
 		for(int j=1;j<=m;j++){
 			s[j]=s[j-1]+a[j];
 			// cout<<s[j]<<' ';
 		}
 		// cout<<endl;
 		int t=m+1;
 		for(int j=1;j<=m;j++){
 			if(s[j]>h){
 				t=j;
 				break;
 			}
 			s[j]+=s[j-1];
 		}
 		t--;
 		node[idx].a=t;
 		node[idx].id=i+1;
 		node[idx++].b=s[t];
 	}   
 	sort(node,node+n);
 	for(int i=0;i<n;i++){
 		if(node[i].id==1){
 			cout<<i+1<<endl;
 			return;
 		}
 	}
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}