#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define endl '\n'

mt19937 rng(time(0));
int main()
{

	int a=rng()%100000+1;
	int b=rng()%100000+1;
	while(abs(a-b)==a||abs(a-b)==b)b=rng()%100000+1;
	cout<<a<<' '<<b<<endl;
	int n=rng()%9+2;
	int m=rng()%999+2;
	cout<<n<<' '<<m<<endl;


	int sz=rng()%n+1;
	set<int>win;
	while(win.size()<sz)win.insert(rng()%n);
	// for(auto i:win)cout<<i<<endl;


	vector<int>v;
	v.push_back(a);
	v.push_back(b);
	unordered_map<int,int>mp;mp[a]=1;mp[b]=1;

	unordered_map<int,int>def;

	int ans[n][m];
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			int f=1;
			if(def.count(i)){
				ans[i][j]=rng()%100000+1;
			}
			if(win.find(i)!=win.end()||rng()%2!=1){
				for(int p=0;p<v.size();p++){
					for(int q=p+1;q<v.size();q++){
						if(!mp.count(abs(v[p]-v[q]))){
							ans[i][j]=abs(v[p]-v[q]);
							goto nx;
						}
					}
				}
			}
			ans[i][j]=rng()%100000+1;
			for(int p=0;p<v.size();p++){
				for(int q=p+1;q<v.size();q++){
					if(ans[i][j]==abs(v[p]-v[q])){
						f=0;
					}
				}
			}
			if(!f){
				def[i]=1;
			}
			nx:{
                mp[ans[i][j]]=1;
                v.push_back(ans[i][j]);
            }
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j]<<' ';
		}cout<<endl;
	}


	return 0;
}
