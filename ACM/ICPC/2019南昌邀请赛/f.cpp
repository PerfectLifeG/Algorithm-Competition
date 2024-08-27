#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) (x&(-x))
const int N=4e5+10;
int tr[N];
int tr2[N];
int n;
void add1(int t,int val){
	for(int i=t;i<=n;i+=lowbit(i)){
		tr[i]^=val;
	}
}
void add2(int t,int val){
	for(int i=t;i<=n;i+=lowbit(i)){
		tr2[i]^=val;
	}
}
int query1(int t){
	int res=0;
	for(int i=t;i;i-=lowbit(i)){
		res^=tr[i];
	}
	return res;
}
int query2(int t){
	int res=0;
	for(int i=t;i;i-=lowbit(i)){
		res^=tr2[i];
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	for(int p=1;p<=T;p++){
		cout<<"Case #"<<p<<":\n";
		int m;cin>>n>>m;
		vector<int>a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i&1){
				add1(i,a[i]);
			}else{
				add2(i,a[i]);
			}
		}
		while(m--){
			int op;cin>>op;
			if(op==1){
				int l,r;cin>>l>>r;
				if((r-l+1)%2==0){
					cout<<0<<endl;
					continue;
				}
				// cout<<l<<' '<<r<<endl;
				if(l&1){
					cout<<(query1(r)^query1(l-1))<<endl;
				}else{
					cout<<(query2(r)^query2(l-1))<<endl;
				}
			}else{
				int x,y;cin>>x>>y;
				if(x&1)add1(x,a[x]^y);
				else add2(x,a[x]^y);
				a[x]=y;
			}
		}
		for(int i=1;i<=n;i++){
			if(i&1)add1(i,a[i]);
			else add2(i,a[i]);
		}
	}
}