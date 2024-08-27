#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int T=1000000;
	double sum=0;
	srand(time(nullptr));
	int n=5;
	while(T--){
		int s=0;
		for(int i=1;i<=n;i++){
			int x=i;
			vector<int>v;
			for(int i=1;i<=n;i++)v.push_back(i);
			int cnt=0;
			int flag=0;
			int flag2=0;
			if(x==1)flag++;
			if(x==n)flag2++;
			while(v.size()){
				cnt++;
				int i=rand()%(v.size());
				if(v[i]==x)break;
				if(v[i]==x-1)flag++;
				if(v[i]==x+1)flag2++;
				if(flag&&flag2)break;
			}
			s+=cnt;
		}
		sum+=(1.0*s/n);
	}
	cout<<(1.0*sum)/1000000<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	// cin>>_;
	while(_--)solve();
}