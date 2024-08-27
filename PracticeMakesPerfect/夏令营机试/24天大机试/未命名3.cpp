#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string s;cin>>s;
		double a;cin>>a;
		double ans;
		if(s=="iou"){
			ans=2*a/(a+1);
		}else {
			ans=a/(2-a);
		}
		printf("%.2f\n",ans);
//		cout<<fixed<<setprecision(2)<<ans<<endl;
	}
} 
