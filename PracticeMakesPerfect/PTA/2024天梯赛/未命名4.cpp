#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define endl '\n'
const int N=10010;
map<string,vector<string>>mp;
int main(){
	int n;cin>>n;
    string s;getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin,s);
        string t;t+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i-1]==' '&&s[i]!=' ')t+=s[i];
        }
        mp[t].push_back(s);
    }
    int q;cin>>q;getline(cin,s);
    while(q--){
        getline(cin,s);string t;t+=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i-1]==' '&&s[i]!=' ')t+=s[i];
        }
        if(mp.count(t)){
            // vector<int>p=;
            sort(all(mp[t]));
            int fir=1;
            for(auto i:mp[t]){
                if(fir){cout<<i;fir=0;}
                else cout<<'|'<<i;
            }cout<<endl;
        }else cout<<s<<endl;
        
        
    }
}
