#include<bits/stdc++.h>
using namespace std;
const int N=10010;
vector<pair<int,int>>v;
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d,e,f;
		scanf("%d:%d:%d - %d:%d:%d",&a,&b,&c,&d,&e,&f);
		int t1=a*3600+b*60+c;
		int t2=d*3600+e*60+f;
		v.push_back({t1,t2});
	}
	sort(v.begin(),v.end());
//	for(auto i:v)cout<<i.first<<' ';
//	cout<<endl;
	int idx=0;
	vector<pair<int,int>>ans;
	for(int i=0;i<v.size();i++){
		if(idx!=v[i].first){
			ans.push_back({idx,v[i].first});
			idx=v[i].second;
		}else idx=v[i].second;
	}
	if(idx!=23*3600+59*60+59){
		ans.push_back({idx,23*3600+59*60+59});
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		int h=ans[i].first/3600;
		int m=ans[i].first%3600/60;
		int s=ans[i].first%3600%60;
		printf("%02d:%02d:%02d - ",h,m,s);
		h=ans[i].second/3600;
		m=ans[i].second%3600/60;
		s=ans[i].second%3600%60;
		printf("%02d:%02d:%02d\n",h,m,s);
	}
	return 0;
}
