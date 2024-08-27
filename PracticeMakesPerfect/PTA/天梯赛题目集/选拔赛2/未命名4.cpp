#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300005;
int nx[N];
int kmp(string p,string s){
    for(int i=2,j=0;i<p.size();i++){
        while(j&&p[i]!=p[j+1])j=nx[j];
        if(p[i]==p[j+1])j++;
        nx[i]=j;
    }
    int n=s.size();
    for(int i=1,j=0;i<p.size();i++){
        while(j&&s[i]!=p[j+1])j=nx[j];
        if(s[i]==p[j+1])j++;
        if(j==n){
            return 1;
        }
    }
}
void solve(){
    string s;cin>>s;
    //string t="";
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(kmp(s.substr(i+1),s.substr(i,j)))ans=max(ans,j);
        }
    }
    cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int _=1;
	//cin>>_;
	while(_--)solve();
}
