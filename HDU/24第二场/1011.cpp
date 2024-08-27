//#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <set>
#include <stack>
#include <bitset>

//#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define lowbit(x) x&(-x)
//#define x first
//#define y second;
using namespace std;

const int N = 1e5+7;
const int mod = 1e9+7;
const double eps = 1e-9;

//----------------------------------------------------------------------


//-----------------------------------------------------------------------

const int mod1=1e9+7;
const int mod2=1e9+9;
const int p1=233333,p2=13131;
int h1[N],h2[N],pw1[N],pw2[N];

pii get_hash(int l,int r){
    int x=((h1[r]-h1[l-1]*pw1[r-l+1])%mod1+mod1)%mod1;
    int y=((h2[r]-h2[l-1]*pw2[r-l+1])%mod2+mod2)%mod2;
    return make_pair(x,y);
}

void str_hash(string s){
    s='?'+s;// 下标从1开始方便处理
    pw1[0]=1; pw2[0]=1;
    for(int i=1;i<s.size();++i){
        pw1[i]=pw1[i-1]*p1%mod1;
        pw2[i]=pw2[i-1]*p2%mod2;
        h1[i]=(h1[i-1]*p1+s[i])%mod1;
        h2[i]=(h2[i-1]*p2+s[i])%mod2;
    }
}

//倍增思想
int sa[N],rk[N<<1],prk[N<<1],w;

void solve(){
	int m; cin>>m;
	string s,c; cin>>s>>c;
	str_hash(c);
	map<pii,int> mp; mp[get_hash(1,sz(c))]=1;
	int n=s.size(); s='?'+s;
	for(int i=1;i<=n;++i)sa[i]=i,rk[i]=s[i];
	for(w=1;w<n;w<<=1){
	    sort(sa+1,sa+n+1,[](int x,int y){
	        return rk[x]==rk[y]? rk[x+w]<rk[y+w]:rk[x]<rk[y];
	    });
	    memcpy(prk,rk,sizeof prk);
	    for(int i=1,p=0;i<=n;++i){
	        if(prk[sa[i]]==prk[sa[i-1]]&&prk[sa[i]+w]==prk[sa[i-1]+w]){
	            rk[sa[i]]=p;
	        }else{
	            rk[sa[i]]=++p;
	        }
	    }
	}
	vector<int> ans;
	for(int k=1;k<=m;++k){
		string b1,b2; cin>>b1>>b2;
		if(b1.size()>n)continue;
		str_hash(b2);
		int f1=0,f2=0;
		for(int i=sz(c);i<=b2.size();++i){
			if(mp.count(get_hash(i-sz(c)+1,i))){
				f1=1;
				break;
			}
		}
		int l=1,r=n-sz(b1)+1;
		while(l<r){
			int mid=l+r>>1;
			if(s.substr(sa[mid],sz(b1))>=b1)r=mid;
			else l=mid+1;
		}
		if(s.substr(sa[l],sz(b1))==b1)f2=1;
//		cout<<f1<<' '<<f2<<endl;
		if(f1&&f2)ans.pb(k);
	}
	for(int i=0;i<ans.size();++i){
		if(i)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
}

signed main()
{
	IOS
	int _ = 1;
	cin>>_;
	while(_--) solve();
    return 0;
}