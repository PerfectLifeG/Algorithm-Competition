#include<bits/stdc++.h>
using namespace std;
int x1,x2,y11,y2;
int n,m;
int main(){
	cin>>n>>m;
	cin>>x1>>y11>>x2>>y2;
	// if(abs(x1-x2)<=1&&abs(y11-y2)<=1){cout<<1;return 0;}
	int cnt=0;
	cnt+=abs(x1-x2);
	cnt+=abs(y11-y2);
	cout<<(cnt+1)/2;
	return 0;
}