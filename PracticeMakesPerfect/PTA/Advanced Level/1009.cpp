#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define x first
#define y second
typedef pair<int,int> PII;
const int N=200010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n;cin>>n;
    unordered_map<int,double>mp1;
    unordered_map<int,double>mp2;
    for(int i=0;i<n;i++){
        int a;double b;cin>>a>>b;
        mp1[a]=b;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int a;double b;cin>>a>>b;
        mp2[a]=b;
    }
    map<int,double,greater<int>>mp;
    for(auto i:mp1){
            // cout<<i.x<<' '<<i.y<<endl;
        for(auto j:mp2){
            if(i.y*j.y!=0)
            mp[i.x+j.x]+=i.y*j.y;
        }
    }
    for(auto itsum:mp){
        if(itsum.second == 0){
            mp.erase(itsum.first);
        }
    }
    cout<<mp.size();
    for(auto i:mp){
        printf(" %d %.1lf",i.x,i.y);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}