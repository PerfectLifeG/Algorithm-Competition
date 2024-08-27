#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"NO"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int>vv;
    for(int i=0;i<n;){
        if(v[i]==0){vv.push_back(v[i]);i++;continue;}
        int j=i+1;
        int t=v[i];
        while(j<n&&v[j]!=0){t+=v[j];j++;}
        vv.push_back(t);
        i=j;
    }
//     for(auto i:vv)cout<<i<<' ';cout<<endl;
    int ans=n-1;
    int t=m;
    multiset<int>st;
    for(int i=0;i<vv.size();i++){
        if(vv[i]>=m){
            no;
            return;
        }else if(vv[i]>=t){
            auto p=st.lower_bound(vv[i]-t+1);
            ans+=*p;
            t+=*p;
            t-=vv[i];
            if(p!=st.end())st.erase(p);
        }else t-=vv[i];
        if(vv[i])st.insert(vv[i]);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}