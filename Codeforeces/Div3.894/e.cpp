#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve()
{
    int n,m,d;cin>>n>>m>>d;
    vector<int>a(n+1);
    multiset<int>st;
    int t=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(st.size()>=m&&a[i]>=*st.begin()){
            t-=*st.begin();
            t+=a[i];
            st.erase(st.begin());
            st.insert(a[i]);
        }else if(st.size()<m&&a[i]>0){st.insert(a[i]);t+=a[i];}
        ans=max(ans,t-i*d);
    }
    cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}