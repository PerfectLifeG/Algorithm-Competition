#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;cin>>n;
	int t=n%4;
	if(t==1){
		cout<<1+n/4*4<<endl;
		cout<<1;
		for(int i=0;i<n/4;i++){
			cout<<"1001";
		}
		cout<<endl;
	}else if(t==2){
		cout<<4+n/4*4<<endl;
		cout<<"0001";
		for(int i=0;i<n/4;i++){
			cout<<"1001";
		}
		cout<<endl;
	}else if(t==3){
		cout<<2+n/4*4<<endl;
		cout<<"01";
		for(int i=0;i<n/4;i++){
			cout<<"1001";
		}
		cout<<endl;
	}else{
		cout<<n/4*4<<endl;
		for(int i=0;i<n/4;i++){
			cout<<"1001";
		}
		cout<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	cin>>_;
	while(_--){
		solve();
	}
}