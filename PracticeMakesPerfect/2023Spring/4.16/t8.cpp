#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	int n;cin>>n;
	unordered_map<int,int>mp;
	int t=0;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		t+=a;
		mp[t+1]++;
		t++;
	}
	string s;
	int idx=1;
	while(cin>>s,s!="End"){
		if(s=="ChuiZi"){
			if(mp.count(idx))cout<<"JianDao"<<endl;
			else cout<<"Bu"<<endl;
		}
		else if(s=="JianDao"){
			if(mp.count(idx))cout<<"Bu"<<endl;
			else cout<<"ChuiZi"<<endl;
		}
		else if(s=="Bu"){
			if(mp.count(idx))cout<<"ChuiZi"<<endl;
			else cout<<"JianDao"<<endl;
		}
		if(idx==t)idx=0;
		idx++;
	}
	return 0;
}
