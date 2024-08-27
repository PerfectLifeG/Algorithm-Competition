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
    set<PII>st;
    for(int i=0;i<n;i++){
        int h,m;cin>>h>>m;
        if(m>=5){
            st.insert({h,m-1});
            st.insert({h,m-3});
            st.insert({h,m-5});
        }else if(m>=3){
            st.insert({h,m-1});
            st.insert({h,m-3});
            st.insert({h-1,60-(5-m)});
        }else if(m>=1){
            st.insert({h,m-1});
            st.insert({h-1,60-(3-m)});
            st.insert({h-1,60-(5-m)});
        }else{
            st.insert({h-1,60-(1-m)});
            st.insert({h-1,60-(3-m)});
            st.insert({h-1,60-(5-m)});
        }
    }
    cout<<st.size()<<endl;
    for(auto [i,j]:st){
        cout<<i<<' '<<j<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}