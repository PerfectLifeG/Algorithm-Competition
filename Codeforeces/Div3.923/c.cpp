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
    int n,m,k;cin>>n>>m>>k;
    vector<int>a(n);
    vector<int>b(m);
    set<int>st;
    set<int>sa;
    set<int>sb;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=k){
            sa.insert(a[i]);st.insert(a[i]);
        }
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(b[i]<=k){
            sb.insert(b[i]);st.insert(b[i]);
        }
    }
    if(st.size()!=k){
        no;
        return;
    }
    if(sa.size()>=k/2&&sb.size()>=k/2)yes;
    else no;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}