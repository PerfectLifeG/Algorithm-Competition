#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+5;
const int inf=1e18;
int a[N];
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) {
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=inf;
		int mm=n-m;
		set<int>st;
		for(int i=0;i<n;i++){
			int t=a[i];
			while(t){
				st.insert(t);
				t/=2;
			}
		}
		for(auto i:st){
			vector<int>w(n+1);
			for(int j=1;j<=n;j++){
				if(a[j]<=i){
					w[j]=i-a[j];
				}else{
					int tmp=a[j];
					int cnt=0;
					int mn=abs(a[j]-i);
					while(tmp/2>=1){
						mn=min(abs(tmp-i)+cnt,mn);
						tmp/=2;
						cnt++;
					}
//					cnt+=(tmp-a[i]);
					w[j]=mn;
				}
			}
			sort(w.begin()+1,w.end());
			int res=0;
			for(int i=1;i<=mm;i++){
				res+=w[i];
			}
			ans=min(ans,res);
		}
		cout<<ans<<'\n';
	}
}