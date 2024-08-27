#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		vector<int>a(n);
		int id=-1;
		double ans=0;
		int t=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			t+=a[i];
			if(id==-1&&i&&a[i]>a[i-1])id=i;
		}
		ans=1.0*t/n;
		int sum=a[id-2]+a[id]+a[id-1];
		ans=max(ans,sum*1.0/3);
		t=0;
		for(int i=id+1;i<n;i++){
			t+=a[i];
		}
		ans=max(ans,1.0*(t+sum)/(n-id+2));
		t=0;
		for(int i=0;i<id-2;i++){
			t+=a[i];
		}
		ans=max(ans,1.0*(t+sum)/(id+1));

		cout<<fixed<<setprecision(15)<<ans<<endl;
	}
}