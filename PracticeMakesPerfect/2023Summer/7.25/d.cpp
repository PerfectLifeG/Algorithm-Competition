#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;

int gcd(int a,int b,map<pii,vector<int>>& mpa,map<pii,vector<int>>& mpb,map<pii,vector<int>>& mpa1,map<pii,vector<int>>& mpb1,int flag){
	if(b==0) return a;
	if(a<b) return gcd(b,a%b,mpa,mpb,mpa1,mpb1,flag^1);
	int z=a%b;
	if(flag){
		if(mpb[{b,z}].empty()) return gcd(b,z,mpa,mpb,mpa1,mpb1,flag^1);
		int sum=upper_bound(mpb[{b,z}].begin(),mpb[{b,z}].end(),a)-mpb[{b,z}].begin();
		mpb1[{b,z}][0]++;mpb1[{b,z}][sum]--;
		return gcd(b,z,mpa,mpb,mpa1,mpb1,flag^1);
	}else{
		if(mpa[{b,z}].empty()) return gcd(b,z,mpa,mpb,mpa1,mpb1,flag^1);
		int sum=upper_bound(mpa[{b,z}].begin(),mpa[{b,z}].end(),a)-mpa[{b,z}].begin();
		mpa1[{b,z}][0]++;mpa1[{b,z}][sum]--;
		return gcd(b,z,mpa,mpb,mpa1,mpb1,flag^1);
	}
}
void solve(){
	int n,q;
	cin>>n>>q;
	vector<pii> re(n);
	for(int i=0;i<n;i++) cin>>re[i].first>>re[i].second;
	vector<pii> req(q);
	map<pii,int> mp;
	map<pii,vector<int>> mpa,mpb;
	for(int i=0;i<q;i++){
		cin>>req[i].first>>req[i].second;
		if(req[i].first==req[i].second) continue;
		else if(req[i].first>req[i].second){
			mpb[{req[i].second,req[i].first%req[i].second}].push_back(req[i].first);
		}else{
			mpa[{req[i].first,req[i].second%req[i].first}].push_back(req[i].second);
		}
	}
	
	for(auto& [a,x]:mpa) sort(x.begin(),x.end());
	for(auto& [a,x]:mpb) sort(x.begin(),x.end());

	map<pii,vector<int>> mpa1,mpb1;
	for(auto& [x,y]:mpa){
		vector<int> z(y.size()+10,0);
		mpa1[x]=z;
	}
	for(auto& [x,y]:mpb){
		vector<int> z(y.size()+10,0);
		mpb1[x]=z;
	}
	
	for(auto [a,b]:re){
		int d=gcd(a,b,mpa,mpb,mpa1,mpb1,1);
		mp[{d,d}]++;
	}

	for(auto& [a,b]:mpa1){
		int sum=0;
		for(int i=0;i<(int)b.size();i++){
			sum+=b[i];b[i]=sum;
		}
	}
	
	for(auto& [a,b]:mpb1){
		int sum=0;
		for(int i=0;i<(int)b.size();i++){
			sum+=b[i];b[i]=sum;
		}
	}
	for(auto& [a,b]:mpa){
		for(int i=0;i<(int)b.size();i++){
			mp[{a.first,b[i]}]=mpa1[a][i];
		}
	}
	for(auto& [a,b]:mpa1){
		int sum=0;
		for(int i=0;i<(int)b.size();i++){
			sum+=b[i];b[i]=sum;
		}
	}
	
	for(auto& [a,b]:mpb1){
		int sum=0;
		for(int i=0;i<(int)b.size();i++){
			sum+=b[i];b[i]=sum;
		}
	}
	for(auto& [a,b]:mpa){
		for(int i=0;i<(int)b.size();i++){
			mp[{a.first,b[i]}]=mpa1[a][i];
		}
	}
	for(auto& [a,b]:mpb){
		for(int i=0;i<(int)b.size();i++){
			mp[{b[i],a.first}]=mpb1[a][i];
		}
	}
	for(auto a:req){
		cout<<mp[a]<<"\n";
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--) solve();
}