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
// int check(int t){
//     while(t){
//         if(t%10==6||t%10==2)return 0;
//         t/=10;
//     }
//     return 1;
// }
void solve(){
    int n;cin>>n;
    unordered_map<int,int>mp;
    mp[0]=0;mp[1]=1;mp[2]=3;mp[3]=4;
    mp[4]=5;mp[5]=7;mp[6]=8;mp[7]=9;
    while(n--){
        int k;cin>>k;
        vector<int>v;
        while(k){
            v.push_back(mp[k%8]);
            k/=8;
        }
        reverse(all(v));
        for(auto i:v)cout<<i;
        cout<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}