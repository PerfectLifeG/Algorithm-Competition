#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int a[7];
int main(){
	for(int i=1;i<=6;i++){
		cin>>a[i];
	}
	int n;cin>>n;
	int b[7]={6,6,6,6,6,6,6};
	for(int i=1;i<=6;i++){
			if(b[i]==a[i])b[i]--;
	}
	for(int j=2;j<=n;j++){
		for(int i=1;i<=6;i++){
			b[i]--;
			if(b[i]==a[i])b[i]--;
		}
	}	
	cout<<b[1];
	for(int i=2;i<=6;i++){
		cout<<' '<<b[i];
	}
	return 0;
}
