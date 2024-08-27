#include<bits/stdc++.h>
using namespace std;
signed main(){
	int n,m;cin>>n>>m;
	double ans=1;
	if(n==1){
		printf("%.15lf",1.0);
		return 0;
	}
	for(int i=0;i<m;i++){
		ans*=(2.0/n);
	}
	printf("%.15lf",ans);
}