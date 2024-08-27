#include<bits/stdc++.h>
using namespace std;
const int N=100100;
int book[N],book2[N];
int main(){
	int n,m,q;cin>>n>>m>>q;
	int row=0,col=0;
	while(q--){
		int op,x;
		cin>>op>>x;
		if(op==0){
			if(book[x])continue;
			book[x]=1;
			row++;
		}else{
			if(book2[x])continue;
			book2[x]=1;
			col++;
		}
	}
	cout<<n*m+col*row-(col*n+row*m);
	return 0;
}
