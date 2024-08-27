#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int N=100010;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	string s;cin>>s;
	string ans;
	for(int i=0;i<s.size();i++){
		if(i!=0&&s[i]>='A'&&s[i]<='Z'){
			ans+=' ';ans+=s[i]+32;
		}
		else ans+=s[i];
	}
	cout<<ans;
	return 0;
}