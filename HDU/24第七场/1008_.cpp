#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
typedef pair<int,int> pii;

const int N = 101, M = 1e6;
const int inf = 2e9;
const int mod = 1e9+7;

mt19937 rd(time(0));

int n,m,L,R;

struct Matrix{
	int a[N][N]; // N?ù?Yìa???ù?????ó′óD???DDμ÷??
	Matrix(int val){
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				a[i][j]=val;
			}
		}
	}
	Matrix operator*(Matrix b){
		Matrix res(0);
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				for(int k=0;k<=n;++k){
					res.a[i][j]=(res.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return res;
	}
};

Matrix qmi(Matrix x,int k){
	Matrix res(0);
	for(int i=0;i<=n;++i)res.a[i][i]=1;
	while(k){
		if(k&1)res=res*x;
		k>>=1;
		x=x*x;
	}
	return res;
}
/*
1
3 3 9999999 10000000
1 2 100
2 3 100
1 4 1
*/

void solve() {
    cin>>n>>m>>L>>R;
    Matrix ans(0),base(0);
    Matrix b1(0),b2(0);
    vector<pii> f[n+1];
    for(int i=0;i<m;++i){
    	int u,v,w; cin>>u>>v>>w;
    	if(v<=n)f[v].pb({u,w});
		else b2.a[u][v-n]+=w,b2.a[u][v-n]%=mod;
	}
	vector<vector<int>> dp(n+1,vector<int>(n+1));
	for(int i=1;i<=n;++i)dp[i][i]=1;
	for(int i=1;i<=n;++i){
		for(auto [pre,w]:f[i]){
			for(int j=1;j<=n;++j){
				dp[j][i]+=dp[j][pre]*w%mod;
				dp[j][i]%=mod;
			}
		}
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)b1.a[i][j]=dp[i][j];
	b1.a[0][0]=1; for(int i=0;i<=n;++i)b2.a[i][0]=1;
	base=b1*b2;
	cout<<"chushi"<<endl;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j)cout<<b1.a[i][j]<<' ';
		cout<<endl;
	}
	// cout<<"b2"<<endl;
	// for(int i=0;i<=n;++i){
	// 	for(int j=0;j<=n;++j)cout<<b2.a[i][j]<<' ';
	// 	cout<<endl;
	// }
	// cout<<"xishu"<<endl;
	// for(int i=0;i<=n;++i){
	// 	for(int j=0;j<=n;++j)cout<<base.a[i][j]<<' ';
	// 	cout<<endl;
	// }
	// cout<<endl;
	// Matrix b3=b1*base;
	// for(int i=0;i<=n;++i){
	// 	for(int j=0;j<=n;++j)cout<<b3.a[i][j]<<' ';
	// 	cout<<endl;
	// }
	// cout<<endl;
	// Matrix tmp(0);
	// for(int i=0;i<=n;i++)tmp.a[1][i]=b1.a[1][i];
	// b1.a[2][1]=0;b1.a[2][2]=0;b1.a[2][3]=0;b1.a[2][4]=0;b1.a[2][5]=0;
	// b1.a[3][1]=0;b1.a[3][2]=0;b1.a[3][3]=0;b1.a[3][4]=0;b1.a[3][5]=0;
	// b1.a[4][1]=0;b1.a[4][2]=0;b1.a[4][3]=0;b1.a[4][4]=0;b1.a[4][5]=0;
	ans.a[0][1]=1;
	int sum=0;
	int p1=L/n*n,p2=R/n*n; if(p1<L)p1+=n;
	Matrix k1=(ans*qmi(base,p1/n-1))*b1,k2(0);

	// cout<<"k1"<<endl;
	// for(int i=0;i<=n;++i){
	// 	for(int j=0;j<=n;++j)cout<<k1.a[i][j]<<' ';
	// 	cout<<endl;
	// }
	// cout<<endl;
	// return;

	if(p1<p2){
//         cout<<p1<<" "<<p2<<"\n";
		k2=(ans*qmi(base,p2/n-1))*b1;
		int s1=k1.a[0][0]; for(int i=1;i<=n;++i)s1+=k1.a[0][i],s1%=mod;
		int s2=k2.a[0][0]; for(int i=1;i<=n;++i)s2+=k2.a[0][i],s2%=mod;
//         for(int i=1;i<=n;++i){
//             cout<<k1.a[0][i]<<" ";
//         }
// 		cout<<endl;
//         cout<<s2<<endl;
		sum+=s2-s1; sum%=mod;
//         cout<<sum<<"\n";
	}
	
	if(L<=p1){
		for(int i=L;i<=min(p1,R);++i){
			int pos=i%n; if(pos==0)pos=n;
			sum+=k1.a[0][pos]; sum%=mod;
//			cout<<pos<<" "<<k1.a[0][pos]<<endl;
		}
	}
	
	if(p2+1<=R&&p2+1>p1){
		Matrix k3=ans*qmi(base,p2/n)*b1;
		for(int i=p2+1;i<=R;++i){
			int pos=i%n; if(pos==0)pos=n;
			sum+=k3.a[0][pos]; sum%=mod;
		}
	}
	cout<<sum<<endl;
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}