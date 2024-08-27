#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=100010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(N);
    for(int i=0;i<n;i++){
        int t;cin>>t;
        a[t]++;
    }
    vector<int>v;
    vector<int>s(N);
    for(auto i:a){
        if(i!=0)v.push_back(i);
    }
    sort(v.begin(),v.end());
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int i=0;i<v.size();i++){
        auto l=lower_bound(a.begin(),a.end(),v[i])-a.begin();
        s[l]+=v[i];
    }
    for(int i=1;i<s.size();i++){
        s[i]+=s[i-1];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        auto l=upper_bound(a.begin(),a.end(),i)-a.begin();
        auto r=upper_bound(v.begin(),v.end(),i)-v.begin();
        cout<<(v.size()-r)*(i-1)+s[l-1]<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}