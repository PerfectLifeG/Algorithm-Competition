#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
// #define x first
// #define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int y1;cin>>y1;
    int n;cin>>n;
    set<int>st;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.insert(a);
    }
    int y2;cin>>y2;
    int t=0;
    for(auto i:st){
        if(i<=y2&&i>=y1){
            t++;
        }
    }
    cout<<y2-y1+1-t<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)solve();
    return 0;
}