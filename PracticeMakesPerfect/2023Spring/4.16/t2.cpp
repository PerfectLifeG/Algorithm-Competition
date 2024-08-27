#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	int x,y;cin>>x>>y;
	int sum=max(0,x+y);
	int mx=max(max(0,x),y);
	if(x<0&&y<0){cout<<0<<' '<<0<<endl<<"-_-";return 0;}
	cout<<mx<<' '<<sum<<endl;
	if(mx<sum)cout<<"^_^"<<endl;
	else if(mx>sum)cout<<"T_T"<<endl;
	else cout<<"-_-";
	return 0;
}
