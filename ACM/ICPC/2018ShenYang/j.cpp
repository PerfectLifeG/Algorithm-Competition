#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
signed main(){
	int T;cin>>T;
	unordered_map<string,int>mp;
	mp["bool"]=1;
	mp["char"]=1;
	mp["int"]=4;
	mp["long long"]=8;
	mp["__int128"]=16;
	mp["float"]=4;
	mp["double"]=8;
	mp["long double"]=16;
	for(int p=1;p<=T;p++){
		int n;cin>>n;
		int ans=0;
		for(int j=0;j<n;j++){
			string op,s;cin>>op;
			if(op=="long"){
				cin>>s;
				op+=' '+s;
			}
			cin>>s;
			// cout<<op<<' '<<s<<endl;
			int num=1;
			for(int i=0;i<s.size();i++){
				int val=0;
				// cout<<i<<' '<<s[i]<<endl;
				int t=0;
				if(s[i]=='['){
					i++;
					while(s[i]!=']'){
						// cout<<f<<' '<<i-1<<endl;
						t*=10;
						t+=s[i]-'0';
						val=t;
						i++;
					}
				}
				if(val){
					num*=val;
					val=0;
				}
			}
			ans+=num*mp[op];
			// cout<<num<<endl;
		}
		cout<<"Case #"<<p<<": "<<(ans+1023)/1024<<endl;
	}
}