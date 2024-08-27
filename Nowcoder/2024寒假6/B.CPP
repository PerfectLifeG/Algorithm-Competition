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
const int INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    set<int>st{-10000000000,10000000000};
    vector<int>b(n);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
        st.insert(a[i]);
    }
    int mn=1e18;
    int ans=0;
    int id=-1;
    for(int i=0;i<n;i++){
        cin>>b[i];
        int aa=*st.lower_bound(b[i]);
        int bb=*prev(st.upper_bound(b[i]));
        cout<<aa<<' '<<bb<<endl;
        if((mn>abs(aa-b[i]))&&abs(aa-b[i])<=abs(bb-b[i])){
            id=i,ans=aa;
        }else if((mn>abs(bb-b[i]))&&abs(aa-b[i])>=abs(bb-b[i])){
            id=i,ans=bb;
        }
        mn=min({mn,abs(bb-b[i]),abs(aa-b[i])});
    }
    swap(a[id],a[mp[a[ans]]]);
    for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}