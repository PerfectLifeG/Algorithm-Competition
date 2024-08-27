#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
int cmp(string a,string b){
    return a+b<b+a;
}
void solve(){
    int n;cin>>n;
    vector<string>v;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        v.push_back(s);
    }
    sort(all(v),cmp);
    string ans;
    for(int i=0;i<v.size();i++){
        ans+=v[i];
    }
    int i=0;int f=1;
    while(ans[i]=='0'&&i<ans.size())i++;
    for(;i<ans.size();i++){cout<<ans[i];f=0;}
    if(f)cout<<0<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}