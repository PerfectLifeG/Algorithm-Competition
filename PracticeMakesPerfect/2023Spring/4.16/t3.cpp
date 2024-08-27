#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	int a,b;cin>>a>>b;
	int t=a+b;
	long long sum=1;
	for(int i=t;i>=2;i--){
		sum*=i;
	}
		cout<<sum;
	return 0;
}
