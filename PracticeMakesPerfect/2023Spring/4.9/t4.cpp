#include<bits/stdc++.h>
using namespace std;
const int N=100100;
const int mod=998244353;
vector<int>v[5];
int main(){
	string s;cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='A')v[0].push_back(i);
		if(s[i]=='c')v[1].push_back(i);
		if(s[i]=='M')v[2].push_back(i);
		if(s[i]=='u')v[3].push_back(i);
		if(s[i]=='P')v[4].push_back(i);
	}
	int ans=0;
	int a,b,c,d;
	for(auto i:v[0]){
		int l=-1,r=v[1].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[0][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[1].size())break;
		a=r;
		l=-1,r=v[2].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[1][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[2].size())break;
		b=r;
		l=-1,r=v[3].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[2][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[3].size())break;
		c=r
		l=-1,r=v[4].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[3][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[4].size())break;
		d=r;
		////////////////////////
		l=-1,r=v[1].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[0][mid]<=i)l=mid;
			else r=mid;
		}
		if(l==v[1].size())break;
		
		l=-1,r=v[2].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[1][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[2].size())break;

		l=-1,r=v[3].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[2][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[3].size())break;

		l=-1,r=v[4].size();
		while(l+1!=r){
			int mid=l+r>>1;
			if(v[3][mid]<i)l=mid;
			else r=mid;
		}
		if(r==v[4].size())break;
	}
	return 0;
}