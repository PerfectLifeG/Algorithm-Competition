#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
void solve(){
    string s;cin>>s;
    char c=s[0];
    int flag=0;
    for(int i=1;i<s.size();i++){
        if(s[i]!=c){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<s.size()-1<<endl;
    }else cout<<-1<<endl;
    
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}