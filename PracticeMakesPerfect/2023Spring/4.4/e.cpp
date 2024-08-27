#include<bits/stdc++.h>
using namespace std;
const int N=200010;
const int mod=998244353;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
#define int long long
void solve(){
    int a;cin>>a;
    string s;
    while(a){
        s+=a%9+'0';
        a/=9;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]>='4')s[i]++;
    }
    reverse(all(s));
    cout<<s<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int T;cin>>T;
    while(T--){
        solve();
    }
    return 0;
}