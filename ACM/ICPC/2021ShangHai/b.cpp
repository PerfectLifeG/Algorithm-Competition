#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define fix(x) fixed<<setprecision(x)
using namespace std;
inline int read(){int x = 0, f = 1;char ch = getchar();while(ch < '0' || ch > '9'){if (ch == '-') f = -1;ch = getchar();}while(ch >= '0' && ch <= '9'){x = (x<<1) + (x<<3) + (ch^48);ch = getchar();}return x * f;}
inline void write(int x){if(x<0) {putchar('-');x = -x;}if(x>9) write(x / 10);putchar(x % 10 + '0');}
using LL=long long;
const int N=2e5+10;

void solve(){
	int p,q;cin>>p>>q;
    int d=__gcd(p,q);
    p/=d;
    q/=d;
    int x=sqrt(p+2*q),y=sqrt(p-2*q);
    if(x*x!=p+2*q||y*y!=p-2*q){
        cout<<"0 0"<<endl;return ;
    }
    cout<<(x+y)/2<<" "<<(x-y)/2<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int _=1;
	cin>>_;
	while(_--){
		solve();
	}
}