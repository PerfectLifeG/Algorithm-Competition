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
    int n,m;cin>>n>>m;
    vector<int>a;
    vector<int>b;
    map<int,int>mp1;
    map<int,int>mp2;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        for(int j=2;j<=t/j;j++){
            if(t%j==0){
                int cnt=0;
                while(t%j==0){
                    cnt++;
                    t/=j;
                }
                mp1[j]+=cnt;
            }
        }
        if(t>1)mp1[t]+=1;
    }
    for(int i=0;i<m;i++){
        int t;cin>>t;
        for(int j=2;j<=t/j;j++){
            if(t%j==0){
                int cnt=0;
                while(t%j==0){
                    cnt++;
                    t/=j;
                }
                mp2[j]+=cnt;
            }
        }
        if(t>1)mp2[t]+=1;
    }
    map<int,int>ans;
    for(auto [i,j]:mp1){
        if(mp2.count(i)){
            ans[i]=min(mp2[i],j);
        }
    }
    if(!ans.size()){
        cout<<1<<' '<<1<<endl;
    }else{
        for(auto [i,j]:ans){
            cout<<i<<' '<<j<<endl;
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}