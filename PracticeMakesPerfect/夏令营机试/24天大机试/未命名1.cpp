#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		double a,b;cin>>a>>b;
		int x=a;
		int y=b;
		if(x<0)x--;
		if(y<0)y--;
		if(a-x<=x+1-a){
			
		}else x++;
		if(b-y<=y+1-b){
			
		}else y++;
		cout<<x<<' '<<y<<endl;
	}
} 
