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
vector<int>nx(N,-1);
void solve(){
    int s1,s2,n;cin>>s1>>s2>>n;
    for(int i=0;i<n;i++){
        int a;string b;int c;cin>>a>>b>>c;
        nx[a]=c;
    }
    unordered_map<int,int>mp;
    for(int i=s1;~i;i=nx[i]){
        mp[i]=1;
    }
    for(int i=s2;~i;i=nx[i]){
        if(mp.count(i)){
            printf("%05d",i);
            return;
        }
    }
    cout<<-1<<endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}