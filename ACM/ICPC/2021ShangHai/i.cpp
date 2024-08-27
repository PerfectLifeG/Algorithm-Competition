#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second
#define PII pair<int,int>
const int N=1e5+10,mod=998244353;
int h(int a,int c) {
	return (a+3000)*1000+c;
}
unordered_map<int,int>mp1,mp2;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	mp1[h(0,k)]=0;
	for(int i=1; i<=n; i++) {
		int x,y;
		cin>>x>>y;
		for(auto w:mp1) {
			int ww=w.f;
			int a=ww/1000-3000,c=ww%1000;
			int aa=a+y;
			if(mp2.count(h(aa,c)))
				mp2[h(aa,c)]=max(mp2[h(aa,c)],w.s+x);
			else
				mp2[h(aa,c)]=w.s+x;
			aa=a-y;
			if(mp2.count(h(aa,c)))
				mp2[h(aa,c)]=max(mp2[h(aa,c)],w.s+x);
			else
				mp2[h(aa,c)]=w.s+x;
			if(c) {
				aa=a+y*2;
				if(mp2.count(h(aa,c-1)))
					mp2[h(aa,c-1)]=max(mp2[h(aa,c-1)],w.s+x);
				else
					mp2[h(aa,c-1)]=w.s+x;
				aa=a-y*2;
				if(mp2.count(h(aa,c-1)))
					mp2[h(aa,c-1)]=max(mp2[h(aa,c-1)],w.s+x);
				else
					mp2[h(aa,c-1)]=w.s+x;
			}
		}
		for(auto w:mp1) {
			if(mp2.count(w.f)) {
				mp2[w.f]=max(w.s,mp2[w.f]);
			} else {
				mp2[w.f]=w.s;
			}
		}
		mp1=mp2;
		mp2.clear();
	}
	int maxx=0;
	for(auto w:mp1) {
		int ww=w.f;
		int a=ww/1000-3000,c=ww%1000;
		if(a==0) {
			maxx=max(maxx,w.s);
		}
	}
	cout<<maxx<<'\n';
}
