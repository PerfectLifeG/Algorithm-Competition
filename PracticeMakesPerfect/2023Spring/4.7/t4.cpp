#include<bits/stdc++.h>
using namespace std;
int cnt;
typedef pair<int,int> PII;
#define x first
#define y second
vector<PII>v;
int cmp(PII a,PII b){
	if(a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}
int main(){
	int n,k,s;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		if(a>=175&&b>=s){cnt++;continue;}
		if(a>=175)v.push_back({a,b});
	}
	sort(v.begin(),v.end(),cmp);
	cout<<cnt<<endl;
	for(auto i:v)cout<<i.x<<' '<<i.y<<endl;
	cout<<endl;
	for(int i=0;i<v.size();){
		int j=i+1;
		while(j<v.size()&&v[j].x==v[i].x){
			cout<<j<<' '<<v[j].x<<' ';
			j++;
		}
		cout<<endl;
		if(j==v.size())j--;
		cnt+=min(k,j-i+1);
		i=j;
		if(j==v.size()-1)i++;
	}
	cout<<cnt;
	return 0;
}