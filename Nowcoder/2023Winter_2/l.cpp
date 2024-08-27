#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
#define no cout<<"No"<<endl
#define yes cout<<"Yes"<<endl
#define endl '\n'
#define x first
#define y second
typedef pair<int,int> PII;
const int N=5010;
const int mod=998244353;
const int INF=0x3f3f3f3f;
void solve(){
    int n,p;cin>>n>>p;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    unordered_map<int,int>mp;
    unordered_map<int,int>mp2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mp[v[i]*v[j]%p]++;
        }
    }
    int a;cin>>a;
    for(int i=0;i<n;i++){
        for(auto [j,k]:mp){
            mp2[(j+v[i])%p]+=k;
        }
        for(int k=0;k<n;k++){
            if(i==k)continue;
            mp2[(v[i]*v[k]+v[i])%p]--;
        }
    }
    for(int i=0;i<p;i++)cout<<mp2[i]*2<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}