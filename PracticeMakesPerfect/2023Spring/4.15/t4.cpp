#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int book[N];
int book2[N];
int row,col;
int main(){
	int n,m,k;cin>>n>>m>>k;
	int sum=0;
	for(int i=0;i<k;i++){
		int op,x;cin>>op>>x;
		if(op==0){
			if(book[x])continue;
			sum+=m;
			book[x]=1;
			row++;
		}else {
			if(book2[x])continue;
			sum+=n;
			book2[x]=1;
			col++;
		}
	}
	sum-=row*col;
	cout<<n*m-sum;
	return 0;
}
