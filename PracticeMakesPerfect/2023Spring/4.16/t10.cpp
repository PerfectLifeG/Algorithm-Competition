#include<bits/stdc++.h>
using namespace std;
const int N=10010;
vector<pair<int,int>>v;
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d,e,f;
		scanf("%d:%d:%d - %d:%d:%d",&a,&b,&c,&d,&e,&f);
		int t=a*3600+b*60+c;
		int t2=d*3600+e*60+f;
		v.push_back({t,t2});
	}
	sort(v.begin(),v.end());
	vector<pair<int,int>>ans;
	int idx=0;
	for(int i=0;i<v.size();i++){
		if(idx!=v[i].first){
			ans.push_back({idx,v[i].first});
		}
		idx=v[i].second;
	}
	if(idx!=23*3600+59*60+59){
		ans.push_back({idx,23*3600+59*60+59});
	}
	for(int i=0;i<ans.size();i++){
		int t=ans[i].first;
		printf("%02d:%02d:%02d - ",t/3600,t%3600/60,t%3600%60);
		t=ans[i].second;
		printf("%02d:%02d:%02d\n",t/3600,t%3600/60,t%3600%60);
	}
	return 0;
}
