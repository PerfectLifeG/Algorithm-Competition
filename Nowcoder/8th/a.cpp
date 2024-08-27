#include<bits/stdc++.h>
using namespace std;
#define int long long
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
    map<string,int>mp;
void solve()
{
    int a;cin>>a;
    for(int i=0;i<a;i++){
        string s;cin>>s;
        mp[s]++;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=1;
    set<string>st;
    cin>>n;
    int a=n;
    while(n--)solve();
    for(auto i:mp){
        if(i.second==a)st.insert(i.first);
    }
    cout<<st.size()<<endl;
    for(auto i:st){
        cout<<i<<endl;
    }
    return 0;
}