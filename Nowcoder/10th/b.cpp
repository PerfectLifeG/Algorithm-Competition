#include<bits/stdc++.h>
using namespace std;
#define int long long
int get(int t){
	int cnt=0;
	while(t){
		cnt++;
		t/=10;
	}
	return cnt;
}
int check(int t,int ans){
	if(t==ans){
		return ans;
	}
	int ca=get(t);
	int a=t*10;
	int b=0;
		// 1250
		// 1205
		// 1025
		// 0125
	int d=10;
	for(int i=0;i<ca+1;i++){
		a=a/d*d+b;
		int p=a;
		// cout<<a<<' '<<b<<endl;
		for(int j=0;j<=9;j++){
			// cout<<p<<endl;
			p=a+j*(d/10);
			if(p==ans){
				return p;
			}
		}
		b=t%d;
		d*=10;
	}
	return -1;
}
void solve(){
	int a,b,c;
	scanf("%lld + %lld = %lld",&a,&b,&c);
	int t=c-b;
	if(check(a,c-b)!=-1){
		cout<<"YES"<<endl;
		cout<<check(a,c-b)<<" + "<<b<<" = "<<c<<endl;
	}else if(check(b,c-a)!=-1){
		cout<<"YES"<<endl;
		cout<<a<<" + "<<check(b,c-a)<<" = "<<c<<endl;
	}else if(check(c,a+b)!=-1){
		cout<<"YES"<<endl;
		cout<<a<<" + "<<b<<" = "<<check(c,a+b)<<endl;
	}else{
		cout<<"NO"<<endl;
	}

}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	// cin>>_;
	while(_--)solve();
}