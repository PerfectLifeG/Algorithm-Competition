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
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,x,y;cin>>n>>x>>y;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    function<int(int)> check=[&](int mid)->int{
        set<int>st;
        if(abs(x-y)<=mid){st.insert(x);st.insert(y);}
        else return 0;
        for(int i=0;i<n;i++){
            if(i&&abs(a[i]-a[i-1])<=mid){
                st.insert(a[i-1]);
            }
            while(st.size()&&*st.begin()<a[i]-mid){
                st.erase(st.begin());
            }
            while(st.size()&&*st.rbegin()>a[i]+mid){
                st.erase(*st.rbegin());
            }
            if(!st.size())return 0;
        }
        return 1;
    };

    int l=0,r=1e9;
    while(l+1!=r){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    cout<<r<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}