#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF=0x3f3f3f3f;
string s;
struct hash{
    #define ll unsigned long long
    const int P=131;
    ll h1[N]={};
    ll h2[N]={};
    ll p[N]={};
    void init(){
        int n=s.size()-1;
        p[0]=1;
        for(int i=1;i<=n;i++){
            p[i]=p[i-1]*P;
            h1[i]=h1[i-1]*P+s[i];
        }
        for(int i=n;i>=1;i--){
            h2[i]=h2[i+1]*P+s[i];
        }
    }
    ll get(int l,int r){
        ll res=h1[r]-h1[l-1]*p[r-l+1];
        return res;
    }
    ll get2(int l,int r){
        ll res=h2[l]-h2[r+1]*p[r-l+1];
        return res;
    }
}hs;
void solve(){
	int n,q;cin>>n>>q;
	cin>>s;s=' '+s;
	hs.init();
	while(q--){
		int a,b;cin>>a>>b;
		if(hs.get(a,b)==hs.get2(a,b)){
			puts("Budada");
		}
		else if((b-a+1)&1){
			puts("Putata");
		}else {
			puts("Budada");
		}
	}
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}