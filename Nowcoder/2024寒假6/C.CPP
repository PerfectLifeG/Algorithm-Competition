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
    set<int>st{0};
    int a=0,b=1;
    while(1){
        if(a+b>1e9)break;
        st.insert(a+b);
        int c=a+b;
        a=b;b=c;
    }
    vector<int>v;
    for(auto i:st)v.push_back(i);
    set<int>s=st;
    unordered_map<int,array<int,3>>mp;
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            for(int k=j;k<v.size();k++){
                mp[v[i]+v[j]+v[k]]={v[i],v[j],v[k]};
            }
        }
    }
    int q;cin>>q;
    while(q--){
        int a;cin>>a;
        if(mp.count(a)){
            auto [i,j,k]=mp[a];cout<<i<<' '<<j<<' '<<k<<endl;
        }else cout<<-1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}