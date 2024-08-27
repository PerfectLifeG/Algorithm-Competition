#include<iostream>
#include<cmath>
using namespace std;
int main(){
	long long  n;  //用int会出现浮点错误
	int start,len=0;
	int cj=1;
	cin>>n; 
	for(int i=2;i<=sqrt(n);i++){ 
		cj=1;
		for(int j=i;cj*j<=n;j++){
			cj=cj*j;
			if(n%cj==0&&j-i+1>len){
				start=i;
				len=j-i+1;
			}
		}
	}
	if(start==0){
		len=1;
		start=n;
	}
	cout<<len<<'\n'<<start;
	for(int i=start+1;i<start+len;i++){
		cout<<'*'<<i; 
	} 
	return 0;
} 