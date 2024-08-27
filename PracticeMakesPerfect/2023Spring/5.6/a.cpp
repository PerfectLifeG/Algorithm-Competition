#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
string ans="codeforces";
void solve(){
    string s;cin>>s;
    int a=0;
    for(int i=0;i<ans.size();i++){
        if(ans[i]!=s[i])a++;
    }
    cout<<a<<endl;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}