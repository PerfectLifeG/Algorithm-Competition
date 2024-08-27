#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=(1<<18)+5,inf=1e18;
int a[N];
signed main() {
	int T;
	cin>>T;
	while(T--) {
		int n;
		cin>>n;
//		cout<<(1<<n)-1<<'\n';
		for(int i=1; i<=(1<<n)-1; i++) cin>>a[i];
		sort(a+1,a+1+(1<<n)-1);
		int len=1;
		int r=0;
		vector<int>q;
		for(int i=1; i<=n; i++) {
			int pre_r=r;
			r+=(r+1);
			if(i==1) {
				q.push_back(a[1]);
				continue;
			}
			bool ok=true;
			int minn=inf;
			int cnt=1;
			for(int j=pre_r+1; j<=r-1; j++) {
//    cout<<((a[cnt]^a[j])==a[r])<<'\n';
				if((a[cnt]^a[j])!=a[r]) {
					ok=false;
					break;
				}
				cnt++;
			}
			if(ok) minn=min(minn,a[r]);
			ok=true;
			cnt=1;
			for(int j=pre_r+2; j<=r; j++) {
				if((a[cnt]^a[j])!=a[pre_r+1]) {
					ok=false;
					break;
				}
				cnt++;
			}
			if(ok) minn=min(minn,a[pre_r+1]);
			if(minn!=inf) q.push_back(minn);
		}
		if(q.size()!=n) {
			cout<<-1<<'\n';
		} else {
			for(int i=0; i<n; i++) {
				cout<<q[i]<<' ';
			}
			cout<<'\n';
		}

	}
}